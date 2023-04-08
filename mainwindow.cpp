#include "mainwindow.h"
#include "tabwidget.h"
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <iostream>
#include <QPushButton>
#include <QObject>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    tabs = new TabWidget(this);
    connect(tabs->addNewPage->addNewButton, &QPushButton::clicked, this, &MainWindow::addService);

    // load tabs from settings
    QSettings settings("Ferdicute", "Ferdicute");
    int size = settings.beginReadArray("tabs");
    qDebug() << "Number of tabs: " << size;
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        addServiceNameUrl(settings.value("name").toString(), settings.value("url").toString());
    }
    settings.endArray();

    tabs->show();
    this->setCentralWidget(tabs);
}

MainWindow::~MainWindow()
{
}

// TODO: remove service function

void MainWindow::addService()
{
    // get name and url from the "add new" page and create a new tab
    // TODO: this should be handled differently to allow for adifferent source of name and url
    QString name = tabs->addNewPage->serviceName->text();
    QString url = tabs->addNewPage->serviceUrl->text();
    addServiceNameUrl(name, url);

    // save new tab to settings
    QSettings settings("Ferdicute", "Ferdicute");
    // read current size
    int size = settings.beginReadArray("tabs");
    qDebug() << "Old number of tabs: " << size;
    settings.endArray();
    // write to a next spot
    settings.beginWriteArray("tabs");
    settings.setArrayIndex(size);
    settings.setValue("name", name);
    settings.setValue("url", url);
    settings.endArray();
}

void MainWindow::addServiceNameUrl(const QString &name, const QString &url)
{
    // load cookies from cache
    // TODO: delete cookies
    QWebEngineProfile *profile = new QWebEngineProfile(QString::fromLatin1("Ferdicute.%1").arg(qWebEngineChromiumVersion()));
    // set useragent, important for Whatsapp to work, otherwise it says that chrome version is too old
    profile->setHttpUserAgent("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.79 Safari/537.36");
    // create a webview
    QWebEngineView *webview = new QWebEngineView(profile, this);
    // load url
    webview->load(QUrl(url));
    // add webview as a tab
    // TODO: load icon
    tabs->addTab(webview, name);
}

