#ifndef __micro_logging_Logger__
#define __micro_logging_Logger__

#include <QtCore/QString>
#include <QtCore/QTextStream>

namespace micro {
namespace logging {


/** Logger. */
class Logger : public QObject {
    public :
        /** Logging level. */
        enum LoggingLevel {
            LEVEL_DEBUG	= 0,
            LEVEL_INFO	= 1,
            LEVEL_WARN	= 2,
            LEVEL_ERROR	= 3,
            LEVEL_FATAL	= 4
         };

    private :
        static LoggingLevel level;      /**< Global logging level. */
        static QTextStream *out;    /**< Global output stream. */
        static int count;               /**< Count of created logger instances. */
        static bool isStreamStdin;

    public :
        /** Returns logging level. */
        static LoggingLevel getLevel() { return Logger::level; }

        /** Sets logging level. */
        static void setLevel(LoggingLevel level) { Logger::level = level; }

        /** Sets output stream. */
        static void setOutputStream(QTextStream *stream)
        {
            if (stream) {
                if (isStreamStdin) {
                    delete out;
                    isStreamStdin = false;
                }
                Logger::out = stream;
            }
            else {
                if (!isStreamStdin) {
                    out = new QTextStream(stdout);
                    isStreamStdin = true;
                }
            }
        }

    private :
        QString name;   /**< Logger name. */

    public :
        /** Constructor. */
        Logger(const QString &name, QObject *parent = 0) : QObject(parent), name(name)
        {
            Logger::count++;

            if (!out) {
                out = new QTextStream(stdout);
                isStreamStdin = true;
            }
        }

        virtual ~Logger() {
            Logger::count--;
            if (Logger::count == 0) {
                if (isStreamStdin) {
                    delete out;
                    out = 0;
                    isStreamStdin = false;
                }
            }
        }

        /** Logs debug message. */
        void debug(const QString &message);

        /** Logs info message. */
        void info(const QString &message);

        /** Logs warn message. */
        void warn(const QString &message);

        /** Logs error message. */
        void error(const QString &message);

        /** Logs fatal message. */
        void fatal(const QString &message);

};

}
}

#endif /* __micro_logging_Logger__ */
