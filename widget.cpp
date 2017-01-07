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
    ui->label4->setText("Thanks for coming in today! Your presence is greatly appreciated.");
    ui->label5->setText("Enter starting cash value in pocket: ");
    ui->label6->setText("Enter 2-character password and choose assigned Driver #: ");
    ui->pushButton->setText("Confirm Cash Value");
    ui->comboBox->addItem("Driver 1");
    ui->comboBox->addItem("Driver 2");
    ui->comboBox->addItem("Driver 3");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startCashButton()));

    //Tab 2
    ui->tabWidget->setTabText(1, "During Work");
    ui->label7->setText("Enter your password:");
    ui->label0->setText("Enter order serial number:");
    ui->label1->setText("Enter order total:");
    ui->label2->setText("Enter tip (If online order):");
    ui->label3->setText("Made a mistake? Erase OSN #:");
    ui->label8->setText("Note: You must enter your password above to delete an OSN.");

    ui->pushButton1->setText("Register This Order");
    ui->pushButton2->setText("Delete This OSN");
    connect(ui->pushButton1, SIGNAL(clicked()), this, SLOT(handleButton()));
    connect(ui->pushButton2, SIGNAL(clicked()), this, SLOT(deleteOSN()));

    //Tab 3
    ui->tabWidget->setTabText(2, "After Work");
    ui->label10->setText("Enter password:");
    ui->label11->setText("List of all orders you've made today:");
    ui->label12->setText("Total value delivered:");
    ui->label13->setText("Click show information for result.");
    ui->pushButton3->setText("Clear Information");
    ui->pushButton4->setText("Show Information");
    connect(ui->pushButton4, SIGNAL(clicked()), this, SLOT(showInfo()));
    connect(ui->pushButton3, SIGNAL(clicked()), this, SLOT(clearInfo()));
}

void Widget::startCashButton(){
    startingCash = ui->spinBox_3->value();
    if(ui->comboBox->currentText() == "Driver 1" && !driver1.filled){
        pdriverNum = 1;
        driver1.driverNum = 1;
        driver1.password = ui->lineEdit->text();
        driver1.filled = true;
    }
    else if(ui->comboBox->currentText() == "Driver 2" && !driver2.filled){
        pdriverNum = 2;
        driver2.driverNum = 2;
        driver2.password = ui->lineEdit->text();
        driver2.filled = true;
    }
    else if(ui->comboBox->currentText() == "Driver 3" && !driver3.filled){
        pdriverNum = 3;
        driver3.driverNum = 3;
        driver3.password = ui->lineEdit->text();
        driver3.filled = true;
    }
    else{
        QMessageBox::information(this, tr("TipMan"), tr("This driver number has already been selected."));
    }
    if(startingCash > 20){
        QMessageBox::information(this, tr("TipMan"), tr("It is not recommended that drivers carry over $20."));
    }
    QString start = "Thank you Driver " + QString::number(pdriverNum) + ". $" +
            QString::number(startingCash) + " set as starting cash value. Re-enter if incorrect.";
    ui->pushButton->setText(start);
}

void Widget::handleButton(){
    QString password = ui->lineEdit_2->text();
    double input = ui->doubleSpinBox->value();
    int osn = ui->spinBox->value();
    ui->doubleSpinBox->setValue(0);
    ui->spinBox->setValue(0);
    ui->lineEdit_2->setText("");

    if(driver1.password != password && driver2.password != password && driver3.password != password){
        QMessageBox::information(this, tr("TipMan"), tr("Invalid password."));
    }
    else{
        if(map.find(osn) != map.end()){
            QMessageBox::information(this, tr("TipMan"), tr("OSN is already registered. Please try again."));
        }
        else if(osn == 0 || input == 0){
            QMessageBox::information(this, tr("TipMan"), tr("Invalid entry. Check OSN and order total, and try again."));
        }
        else{
            Order insertOrder;
            if(ui->checkBox->isChecked()){
                insertOrder.online = true;
                insertOrder.onlineTipVal = ui->doubleSpinBox_2->value();
                if(driver1.password == password){
                    driver1.onlineTipTotal += ui->doubleSpinBox_2->value();
                }
                else if(driver2.password == password){
                    driver2.onlineTipTotal += ui->doubleSpinBox_2->value();
                }
                else{
                    driver3.onlineTipTotal += ui->doubleSpinBox_2->value();
                }
            }
            else{
                if(driver1.password == password){
                    driver1.payWithCashTotal += input;
                }
                else if(driver2.password == password){
                    driver2.payWithCashTotal += input;
                }
                else{
                    driver3.payWithCashTotal += input;
                }
            }
            insertOrder.driverPassword = password;
            insertOrder.price = input;
            std::pair<int, Order> map_input(osn, insertOrder);
            ui->plainTextEdit->clear();
            for(it = map.begin(); it != map.end(); ++it){
                if(password == (it->second).driverPassword){
                    printVal = "OSN " + QString::number(it->first) + ": $" + QString::number((it->second).price);
                    ui->plainTextEdit->appendPlainText(printVal);
                }
            }
            map.emplace(map_input);
            printVal = "OSN " + QString::number(osn) + ": $" + QString::number(input);
            ui->plainTextEdit->appendPlainText(printVal);
            ++orderCount;
        }
    }
}

void Widget::deleteOSN(){
    QString password = ui->lineEdit_2->text();
    int input = ui->spinBox_2->value();
    if(map[input].driverPassword != password){
        QMessageBox::information(this, tr("TipMan"), tr("You cannot delete this OSN"));
    }
    else{
        if(map[input].online == true){
            if(driver1.password == password){
                driver1.onlineTipTotal -= map[input].onlineTipVal;
            }
            else if(driver2.password == password){
                driver2.onlineTipTotal -= map[input].onlineTipVal;
            }
            else{
                driver3.onlineTipTotal -= map[input].onlineTipVal;
            }
        }
        else{
            if(driver1.password == password){
                driver1.payWithCashTotal -= map[input].price;
            }
            else if(driver2.password == password){
                driver2.payWithCashTotal -= map[input].price;
            }
            else{
                driver3.payWithCashTotal -= map[input].price;
            }
        }
        map.erase(input);
        ui->plainTextEdit->clear();
        for(it = map.begin(); it != map.end(); ++it){
            if(password == (it->second).driverPassword){
                printVal = "OSN " + QString::number(it->first) + ": $" + QString::number((it->second).price);
                ui->plainTextEdit->appendPlainText(printVal);
            }
        }
    }
    ui->lineEdit_2->setText("");
    ui->spinBox_2->setValue(0);
}

void Widget::showInfo(){
    double returnTotal = 0;
    QString password = ui->lineEdit_3->text();
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->label13->setText("Click show information for result.");
    ui->plainTextEdit_2->clear();

    if(driver1.password != password && driver2.password != password && driver3.password != password){
        QMessageBox::information(this, tr("TipMan"), tr("Invalid password."));
    }
    else{
        for(it = map.begin(); it != map.end(); ++it){
            if(password == (it->second).driverPassword){
                printVal = "OSN " + QString::number(it->first) + ": $" + QString::number((it->second).price);
                ui->plainTextEdit_2->appendPlainText(printVal);
                returnTotal += (it->second).price;
            }
        }
        QString total = "$" + QString::number(returnTotal);
        ui->lineEdit_4->setText(total);

        double owedAmount = 0;
        if(password == driver1.password){
            owedAmount = driver1.payWithCashTotal - driver1.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label13->setText("The manager owes you:");
                ui->lineEdit_5->setText(QString::number(owedAmount));
            }
            else{
                ui->label13->setText("You owe the manager:");
                ui->lineEdit_5->setText(QString::number(owedAmount));
            }
        }
        else if(password == driver2.password){
            owedAmount = driver2.payWithCashTotal - driver2.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label13->setText("The manager owes you:");
                ui->lineEdit_5->setText(QString::number(owedAmount));
            }
            else{
                ui->label13->setText("You owe the manager:");
                ui->lineEdit_5->setText(QString::number(owedAmount));
            }
        }
        else{
            owedAmount = driver3.payWithCashTotal - driver3.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label13->setText("The manager owes you:");
                ui->lineEdit_5->setText(QString::number(owedAmount));
            }
            else{
                ui->label13->setText("You owe the manager:");
                ui->lineEdit_5->setText(QString::number(owedAmount));

            }
        }
        // take cashtotal, and subtract online tips. if pos, must give manager money. If neg, manager gives you money.
    }
}

void Widget::clearInfo(){
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->label13->setText("Click show information for result.");
    ui->plainTextEdit_2->clear();
}

QString Widget::name() const{
    return ui->pushButton1->text();
}
