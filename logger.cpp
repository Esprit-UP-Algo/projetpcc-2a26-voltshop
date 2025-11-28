#include "logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QCoreApplication>
#include <QMutex>
#include <csignal>
#include <cstdlib>
#ifdef Q_OS_WIN
#include <windows.h>
#include <dbghelp.h>
#endif

static QFile g_logFile;
static QMutex g_logMutex;
static bool g_symInitialized = false;
static HANDLE g_hProcess = nullptr;

#ifdef Q_OS_WIN
static void initSymbols();
#endif

static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context);
    QMutexLocker locker(&g_logMutex);
    if (!g_logFile.isOpen()) {
        // try to open in application directory
        QString fn = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
        g_logFile.setFileName(fn);
        g_logFile.open(QIODevice::Append | QIODevice::Text);
    }
    if (!g_logFile.isOpen()) return;

    QTextStream out(&g_logFile);
    const QString now = QDateTime::currentDateTime().toString(Qt::ISODate);
    QString level;
    switch (type) {
    case QtDebugMsg: level = "DEBUG"; break;
    case QtInfoMsg: level = "INFO"; break;
    case QtWarningMsg: level = "WARN"; break;
    case QtCriticalMsg: level = "CRIT"; break;
    case QtFatalMsg: level = "FATAL"; break;
    }
    out << now << " [" << level << "] " << msg << "\n";
    out.flush();

    // Also write to stderr so IDEs (Qt Creator) and consoles see the output.
    QByteArray line = QString("%1 [%2] %3\n").arg(now, level, msg).toLocal8Bit();
    fwrite(line.constData(), 1, line.size(), stderr);
    fflush(stderr);
#ifdef Q_OS_WIN
    // Also send to the debugger output on Windows so the Debug view shows messages.
    OutputDebugStringA(line.constData());
#endif
}

void initLogger()
{
    qInstallMessageHandler(messageHandler);
    // write header
    QMutexLocker locker(&g_logMutex);
    QString fn = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
    g_logFile.setFileName(fn);
    g_logFile.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&g_logFile);
    out << "\n--- VoltShop log start: " << QDateTime::currentDateTime().toString(Qt::ISODate) << " ---\n";
    out.flush();

#ifdef Q_OS_WIN
    // Initialize symbol handler early (once) to improve symbol resolution in signal handlers
    initSymbols();
#endif

    // Install terminate handler to capture unexpected termination
    std::set_terminate([](){
        QMutexLocker locker(&g_logMutex);
        if (!g_logFile.isOpen()) {
            QString fn = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
            g_logFile.setFileName(fn);
            g_logFile.open(QIODevice::Append | QIODevice::Text);
        }
        QTextStream out(&g_logFile);
        out << QDateTime::currentDateTime().toString(Qt::ISODate) << " [FATAL] std::terminate called\n";
        out.flush();
        // restore default and rethrow
        std::abort();
    });

    // Signal handlers
    std::signal(SIGSEGV, [](int){
        QMutexLocker locker(&g_logMutex);
        if (!g_logFile.isOpen()) {
            QString fn = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
            g_logFile.setFileName(fn);
            g_logFile.open(QIODevice::Append | QIODevice::Text);
        }
        QTextStream out(&g_logFile);
        out << QDateTime::currentDateTime().toString(Qt::ISODate) << " [FATAL] SIGSEGV received\n";
        // Attempt to dump a small backtrace (addresses) and resolve symbols on Windows
    #ifdef Q_OS_WIN
        void* stack[62];
        USHORT frames = CaptureStackBackTrace(0, 62, stack, nullptr);
        out << "Backtrace (most recent first):\n";

        HANDLE hProcess = GetCurrentProcess();
        // Initialize symbols for the process (no-op if already initialized)
        SymInitialize(hProcess, NULL, TRUE);

        for (USHORT i = 0; i < frames; ++i) {
            DWORD64 addr = (DWORD64)(stack[i]);
            // Try to get symbol name
            const int MAX_NAME = 1024;
            BYTE buffer[sizeof(SYMBOL_INFO) + MAX_NAME];
            PSYMBOL_INFO pSym = (PSYMBOL_INFO)buffer;
            pSym->SizeOfStruct = sizeof(SYMBOL_INFO);
            pSym->MaxNameLen = MAX_NAME;
            DWORD64 displacement = 0;
            BOOL ok = SymFromAddr(hProcess, addr, &displacement, pSym);

            // Try to get file/line
            IMAGEHLP_LINE64 lineInfo = {0};
            lineInfo.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
            DWORD displacement32 = 0;
            BOOL gotLine = SymGetLineFromAddr64(hProcess, addr, &displacement32, &lineInfo);

            if (ok) {
            out << QString("  0x%1: %2 + 0x%3").arg((qulonglong)addr, 0, 16).arg(QString::fromLatin1(pSym->Name)).arg((qulonglong)displacement, 0, 16);
            if (gotLine) {
                out << QString(" (%1:%2)").arg(QString::fromLocal8Bit(lineInfo.FileName)).arg(lineInfo.LineNumber);
            }
            out << "\n";
            } else {
            out << QString("  0x%1\n").arg((qulonglong)addr, 0, 16);
            }
        }
    #else
        out << "Backtrace not available on this platform.\n";
    #endif
        out.flush();
        std::abort();
    });
    std::signal(SIGABRT, [](int){
        QMutexLocker locker(&g_logMutex);
        if (!g_logFile.isOpen()) {
            QString fn = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
            g_logFile.setFileName(fn);
            g_logFile.open(QIODevice::Append | QIODevice::Text);
        }
        QTextStream out(&g_logFile);
        out << QDateTime::currentDateTime().toString(Qt::ISODate) << " [FATAL] SIGABRT received\n";
#ifdef Q_OS_WIN
        void* stack[62];
        USHORT frames = CaptureStackBackTrace(0, 62, stack, nullptr);
        out << "Backtrace (most recent first):\n";
        for (USHORT i = 0; i < frames; ++i) {
            out << QString("  0x%1\n").arg((qulonglong)(stack[i]), 0, 16);
        }
#else
        out << "Backtrace not available on this platform.\n";
#endif
        out.flush();
        std::abort();
    });
}

// Initialize symbol handler for Windows so signal-time symbol resolution works
#ifdef Q_OS_WIN
static void initSymbols()
{
    if (g_symInitialized) return;
    g_hProcess = GetCurrentProcess();
    // Request line numbers
    SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
    if (SymInitialize(g_hProcess, NULL, TRUE)) {
        g_symInitialized = true;
    }
}
#endif

void shutdownLogger()
{
    QMutexLocker locker(&g_logMutex);
    if (g_logFile.isOpen()) {
        QTextStream out(&g_logFile);
        out << "--- VoltShop log end: " << QDateTime::currentDateTime().toString(Qt::ISODate) << " ---\n";
        out.flush();
        g_logFile.close();
    }
#ifdef Q_OS_WIN
    if (g_symInitialized && g_hProcess) {
        SymCleanup(g_hProcess);
        g_symInitialized = false;
        g_hProcess = nullptr;
    }
#endif
}
