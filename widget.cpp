#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) //sets ui variable as the ui
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/*
 * void Widget::setButton1(const QString &name){
    ui->pushButton1->setText(name); //lineEdit variable name can be set in ui file design
}
*/
void Widget::decorate(){
    //Tab 1
    ui->tabWidget->setTabText(0, "Before Work");

    //Tab 2
    ui->tabWidget->setTabText(1, "During Work");
    ui->label1->setText("Enter order total:");
    ui->label2->setText("Enter tip (If online order):");
    ui->pushButton1->setText("Register This Order");
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(handleButton()));

    //Tab 3
    ui->tabWidget->setTabText(2, "After Work");

}

void Widget::handleButton(){
    double input = ui->doubleSpinBox->value();
    ui->doubleSpinBox->setValue(0);
    QString printVal = "Order " + QString::number(orderCount) + ": $" + QString::number(input);
    ui->plainTextEdit->appendPlainText(printVal);
    orderCount++;
}

QString Widget::name() const{
    return ui->pushButton1->text();
}
