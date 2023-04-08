#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFile>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // import qss
    // TODO: make an option for custom css and/or default OS look
    QFile file(":/Ferdicute.qss");
    if(file.open(QFile::ReadOnly)) {
       QString styleSheet = QLatin1String(file.readAll());
       qApp->setStyleSheet(styleSheet);
       qDebug() << "Imported QSS";
    }
    else qDebug() << "No QSS";

    MainWindow w;
    w.show();
    return a.exec();
}
