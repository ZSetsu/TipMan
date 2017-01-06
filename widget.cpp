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
    ui->pushButton1->setText("Add Order");
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(handleButton()));
}

void Widget::handleButton(){
    ui->pushButton1->setText("Clicked!");
    int input = ui->lineEdit1->text().toDouble();
    ui->lineEdit1->setText("");

}

QString Widget::name() const{
    return ui->pushButton1->text();
}
