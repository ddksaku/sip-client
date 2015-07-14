#include "Logger.h"
#include <QtCore/QDateTime>

using namespace micro::logging;

Logger::LoggingLevel Logger::level = LEVEL_DEBUG;
QTextStream *Logger::out = 0;
int Logger::count = 0;
bool Logger::isStreamStdin = false;

void Logger::debug(const QString &message)
{
    if (level <= LEVEL_DEBUG) {
        *out << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") << " - " << name << " [debug] : " << message << endl;
    }
}

void Logger::info(const QString &message)
{
    if (level <= LEVEL_INFO) {
        *out << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") << " - " << name << " [info] : " << message << endl;
    }
}

void Logger::warn(const QString &message)
{
    if (level <= LEVEL_WARN) {
        *out << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") << " - " << name << " [warn] : " << message << endl;
    }
}

void Logger::error(const QString &message)
{
    if (level <= LEVEL_ERROR) {
        *out << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") << " - " << name << " [error] : " << message << endl;
    }
}

void Logger::fatal(const QString &message)
{
    if (level <= LEVEL_FATAL) {
        *out << QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss") << " - " << name << " [fatal] : " << message << endl;
    }
}
