#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addServiceNameUrl(const QString &name, const QString &url);

public slots:
    void addService();

private:
    TabWidget *tabs;
};
#endif // MAINWINDOW_H
