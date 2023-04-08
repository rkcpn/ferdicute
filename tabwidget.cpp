#include "tabwidget.h"
#include "tabbar.h"
#include "addnewwidget.h"

TabWidget::TabWidget(QWidget *parent):QTabWidget(parent)
{
    setTabBar(new TabBar);
    setTabPosition(QTabWidget::West); // put tab bar on the left

    // add "add new" widget as a tab page
    addNewPage = new AddNewWidget(this);
    this->addTab(addNewPage, "+");
}
