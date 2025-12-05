#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QDateTime>

class Logger
{
public:
    enum LogLevel {
        Debug,
        Info,
        Warning,
        Error,
        Critical
    };

    static Logger& instance();
    
    // Log methods
    static void debug(const QString &msg);
    static void info(const QString &msg);
    static void warning(const QString &msg);
    static void error(const QString &msg);
    static void critical(const QString &msg);
    
    // Install signal handlers for crash detection
    static void installSignalHandlers();

private:
    Logger();
    ~Logger();
    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    void log(LogLevel level, const QString &msg);
    QString levelToString(LogLevel level) const;
    
    QFile m_logFile;
    QTextStream m_stream;
    QMutex m_mutex;
    
    // Signal handlers
#ifdef Q_OS_WIN
    static void signalHandler(int signal);
    static void writeBacktrace(const QString &reason);
#endif
};

// Convenience macros
#define LOG_DEBUG(msg) Logger::debug(msg)
#define LOG_INFO(msg) Logger::info(msg)
#define LOG_WARNING(msg) Logger::warning(msg)
#define LOG_ERROR(msg) Logger::error(msg)
#define LOG_CRITICAL(msg) Logger::critical(msg)

#endif // LOGGER_H
