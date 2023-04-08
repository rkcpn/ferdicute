#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "addnewwidget.h"

// custom tab widget class
class TabWidget : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget *parent=nullptr);

    AddNewWidget *addNewPage;
};

#endif // TABWIDGET_H
