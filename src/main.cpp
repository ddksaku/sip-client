#include <QtGui/QApplication>
#include <QtCore/QtGlobal>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include "MainWindow.h"
#include "logging/Logger.h"

using namespace micro::logging;

QFile file;
QTextStream *logStream = 0;

void initLogging()
{
    // setup logging
    Logger::setLevel(Logger::LEVEL_DEBUG);

    QDir dir(".");
    if (!dir.exists("./logs")) {
        dir.mkdir("./logs");
    }

    file.setFileName("./logs/app.log");
    if (file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
         logStream = new QTextStream(&file);
         Logger::setOutputStream(logStream);
    }
}

void destroyLogging()
{
    if (file.isOpen()) {
        Logger::setOutputStream(0);
        delete logStream;
        file.close();
    }
}



int main(int argc, char *argv[])
{
    QApplication application(argc, argv);


    // initialize logging
    initLogging();

    // create and show main window
    MainWindow window;
#ifdef Q_OS_WINCE
    window.showMaximized();
#else
    window.show();
#endif

    // run main loop
    int status = application.exec();

    // clean-up
    destroyLogging();

    return status;
}
