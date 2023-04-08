#include "addnewwidget.h"
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>

AddNewWidget::AddNewWidget(QWidget *parent):QWidget(parent)
{
    layout = new QFormLayout(this);
    addNewButton = new QPushButton("Add new service", this);
    serviceName = new QLineEdit(this);
    serviceUrl = new QLineEdit(this);
    this->setLayout(layout);
    layout->addRow(tr("&Name:"), serviceName);
    layout->addRow(tr("&URL:"), serviceUrl);
    layout->addRow(addNewButton);
}

//void AddNewWidget::verify()
//{
//    if (!serviceName->text().isEmpty() && !serviceUrl->text().isEmpty()) {
//        accept();
//        return;
//    }

//    QMessageBox::StandardButton answer;
//    answer = QMessageBox::warning(this, tr("Incomplete Form"),
//        tr("The form does not contain all the necessary information.\n"),
//        QMessageBox::Ok);
//}
