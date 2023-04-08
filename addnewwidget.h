#ifndef ADDNEWWIDGET_H
#define ADDNEWWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>

// widget class for adding a new tab
class AddNewWidget : public QWidget
{
    Q_OBJECT

public:
    AddNewWidget(QWidget *parent=nullptr);

    QString senderName() const;
    QString senderAddress() const;
    QLineEdit *serviceName;
    QLineEdit *serviceUrl;
    QPushButton *addNewButton;

//public slots:
//    void verify();

private:
    QFormLayout *layout;
};

#endif // ADDNEWWIDGET_H
