#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>

// tabbar class that implements vertical tab bar
class TabBar : public QTabBar
{
    Q_OBJECT

public:
    TabBar();
    QSize tabSizeHint(int index) const;
protected:
    void paintEvent(QPaintEvent * /*event*/);
};

#endif // TABBAR_H
