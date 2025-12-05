#include "logger.h"
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <iostream>

#ifdef Q_OS_WIN
#include <windows.h>
#include <dbghelp.h>
#include <signal.h>
#pragma comment(lib, "dbghelp.lib")
#endif

Logger::Logger()
{
    QString logPath = QCoreApplication::applicationDirPath() + "/voltshop_debug.log";
    m_logFile.setFileName(logPath);
    
    if (m_logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        m_stream.setDevice(&m_logFile);
        log(Info, "=== Logger initialized ===");
    } else {
        qWarning() << "Failed to open log file:" << logPath;
    }
}

Logger::~Logger()
{
    if (m_logFile.isOpen()) {
        log(Info, "=== Logger shutting down ===");
        m_stream.flush();
        m_logFile.close();
    }
}

Logger& Logger::instance()
{
    static Logger inst;
    return inst;
}

void Logger::debug(const QString &msg)
{
    instance().log(Debug, msg);
}

void Logger::info(const QString &msg)
{
    instance().log(Info, msg);
}

void Logger::warning(const QString &msg)
{
    instance().log(Warning, msg);
}

void Logger::error(const QString &msg)
{
    instance().log(Error, msg);
}

void Logger::critical(const QString &msg)
{
    instance().log(Critical, msg);
}

void Logger::log(LogLevel level, const QString &msg)
{
    QMutexLocker locker(&m_mutex);
    
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz");
    QString levelStr = levelToString(level);
    QString fullMsg = QString("[%1] [%2] %3").arg(timestamp, levelStr, msg);
    
    // Write to file
    if (m_logFile.isOpen()) {
        m_stream << fullMsg << Qt::endl;
        m_stream.flush();
    }
    
    // Write to stderr
    std::cerr << fullMsg.toStdString() << std::endl;
    
    // Write to Windows debug output
#ifdef Q_OS_WIN
    OutputDebugStringW(reinterpret_cast<const wchar_t*>(fullMsg.utf16()));
    OutputDebugStringW(L"\n");
#endif
}

QString Logger::levelToString(LogLevel level) const
{
    switch (level) {
        case Debug:    return "DEBUG";
        case Info:     return "INFO ";
        case Warning:  return "WARN ";
        case Error:    return "ERROR";
        case Critical: return "CRIT ";
        default:       return "UNKN ";
    }
}

#ifdef Q_OS_WIN
void Logger::signalHandler(int signal)
{
    QString reason;
    switch (signal) {
        case SIGSEGV:
            reason = "SIGSEGV (Segmentation fault)";
            break;
        case SIGABRT:
            reason = "SIGABRT (Abort)";
            break;
        case SIGFPE:
            reason = "SIGFPE (Floating point exception)";
            break;
        case SIGILL:
            reason = "SIGILL (Illegal instruction)";
            break;
        default:
            reason = QString("Unknown signal %1").arg(signal);
            break;
    }
    
    Logger::critical(QString("*** CRASH DETECTED: %1 ***").arg(reason));
    writeBacktrace(reason);
    
    // Re-raise signal for default handler
    ::signal(signal, SIG_DFL);
    ::raise(signal);
}

void Logger::writeBacktrace(const QString &reason)
{
    Logger::critical("Capturing stack trace...");
    
    HANDLE process = GetCurrentProcess();
    HANDLE thread = GetCurrentThread();
    
    // Initialize symbol handler
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
    if (!SymInitialize(process, NULL, TRUE)) {
        Logger::error("Failed to initialize symbol handler");
        return;
    }
    
    // Capture stack frames
    CONTEXT context;
    RtlCaptureContext(&context);
    
    STACKFRAME64 frame;
    memset(&frame, 0, sizeof(frame));
    
#ifdef _M_X64
    DWORD machineType = IMAGE_FILE_MACHINE_AMD64;
    frame.AddrPC.Offset = context.Rip;
    frame.AddrFrame.Offset = context.Rbp;
    frame.AddrStack.Offset = context.Rsp;
#else
    DWORD machineType = IMAGE_FILE_MACHINE_I386;
    frame.AddrPC.Offset = context.Eip;
    frame.AddrFrame.Offset = context.Ebp;
    frame.AddrStack.Offset = context.Esp;
#endif
    
    frame.AddrPC.Mode = AddrModeFlat;
    frame.AddrFrame.Mode = AddrModeFlat;
    frame.AddrStack.Mode = AddrModeFlat;
    
    Logger::critical("Stack trace:");
    
    for (int frameNum = 0; frameNum < 25; ++frameNum) {
        if (!StackWalk64(machineType, process, thread, &frame, &context,
                        NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL)) {
            break;
        }
        
        if (frame.AddrPC.Offset == 0) {
            break;
        }
        
        // Get symbol name
        char symbolBuffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO symbol = (PSYMBOL_INFO)symbolBuffer;
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;
        
        DWORD64 displacement = 0;
        QString symbolName = "???";
        
        if (SymFromAddr(process, frame.AddrPC.Offset, &displacement, symbol)) {
            symbolName = QString::fromLocal8Bit(symbol->Name);
        }
        
        // Get line info
        IMAGEHLP_LINE64 line;
        line.SizeOfStruct = sizeof(line);
        DWORD lineDisplacement = 0;
        QString lineInfo;
        
        if (SymGetLineFromAddr64(process, frame.AddrPC.Offset, &lineDisplacement, &line)) {
            lineInfo = QString(" [%1:%2]").arg(line.FileName).arg(line.LineNumber);
        }
        
        Logger::critical(QString("  #%1: 0x%2 %3%4")
            .arg(frameNum, 2, 10, QChar('0'))
            .arg(frame.AddrPC.Offset, 0, 16)
            .arg(symbolName)
            .arg(lineInfo));
    }
    
    SymCleanup(process);
}
#endif

void Logger::installSignalHandlers()
{
#ifdef Q_OS_WIN
    ::signal(SIGSEGV, signalHandler);
    ::signal(SIGABRT, signalHandler);
    ::signal(SIGFPE, signalHandler);
    ::signal(SIGILL, signalHandler);
    
    Logger::info("Signal handlers installed");
#endif
}
