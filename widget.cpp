#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget) //sets ui variable as the ui
{
    ui->setupUi(this);
    QPixmap pix("D:/GitRepo/TipMan/logo_san-fu.png");
    ui->label->setPixmap(pix);
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
    //ui->label5->setText("Enter starting cash value in pocket: ");
    ui->label6->setText("Enter 2-character password and choose assigned Driver #: ");
    ui->pushButton->setText("Confirm Password");
    ui->comboBox->addItem("Driver 1");
    ui->comboBox->addItem("Driver 2");
    ui->comboBox->addItem("Driver 3");
    ui->comboBox->addItem("Admin");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startCashButton()));

    //Tab 2
    ui->tabWidget->setTabText(1, "During Work");
    ui->label7->setText("Enter your password:");
    ui->label0->setText("Enter order serial number:");
    ui->label1->setText("Enter order total:");
    ui->label3->setText("Made a mistake? Erase OSN #:");
    ui->label8->setText("Note: You must enter your password above to delete an OSN.");
    ui->checkBox->setText("Online order? Enter tip amount if so:");

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

    //Tab4
    ui->tabWidget->setTabText(3, "Admin");
    ui->label20->setText("Enter Admin password:");
    ui->label21->setText("No info to display.");
    ui->label22->setText("Total:");
    ui->comboBox_2->addItem("All Deliveries");
    ui->comboBox_2->addItem("Driver 1");
    ui->comboBox_2->addItem("Driver 2");
    ui->comboBox_2->addItem("Driver 3");
    ui->pushButton_2->setText("Show Information");
    ui->pushButton_3->setText("Clear Information");

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(adminInfo()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(adminClear()));
}

void Widget::startCashButton(){
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
    else if(ui->comboBox->currentText() == "Admin" && !admin.filled){
        admin.filled = true;
        admin.password = ui->lineEdit->text();
    }
    else{
        QMessageBox::information(this, tr("TipMan"), tr("This driver number has already been selected."));
    }
    QString start = "Thank you Driver " + QString::number(pdriverNum) + ". Your password has been set.";
    QString startAdmin = "Thank you Admin, your password has been set.";
    if(ui->comboBox->currentText() == "Admin"){
        ui->pushButton->setText(startAdmin);
    }
    else{
        ui->pushButton->setText(start);
    }
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
                    printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                    if((it->second).online){
                        printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                    }
                    else{
                        printVal += "\tCash";
                    }
                    ui->plainTextEdit->appendPlainText(printVal);
                }
            }
            map.emplace(map_input);
            printVal = "OSN " + QString::number(osn) + ": \t$" + QString::number(input);
            if(map_input.second.online){
                printVal = printVal + "\tOnline tip: $" + QString::number(map_input.second.onlineTipVal);
            }
            else{
                printVal += "\tCash";
            }
            ui->plainTextEdit->appendPlainText(printVal);
            ++orderCount;
        }
    }
    ui->checkBox->setChecked(false);
    ui->doubleSpinBox_2->setValue(0);
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
                printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                if((it->second).online){
                    printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                }
                else{
                    printVal += "\tCash";
                }
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
                printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                if((it->second).online){
                    printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                }
                else{
                    printVal += "\tCash";
                }
                ui->plainTextEdit_2->appendPlainText(printVal);
                returnTotal += (it->second).price;
                }
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


void Widget::clearInfo(){
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->label13->setText("Click show information for result.");
    ui->plainTextEdit_2->clear();
}

void Widget::adminInfo(){
    double total = 0;
    double owedAmount = 0;
    QString totalVal = "";
    ui->plainTextEdit_3->clear();
    ui->lineEdit_7->setText(0);
    ui->lineEdit_8->setText(0);
    if(ui->lineEdit_6->text() == admin.password){
        if(ui->comboBox_2->currentText() == "All Deliveries"){
            for(it = map.begin(); it != map.end(); ++it){
                printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                if((it->second).online){
                    printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                }
                else{
                    printVal += "\tCash";
                }
                ui->plainTextEdit_3->appendPlainText(printVal);
                total += (it->second).price;
            }
            totalVal = "$" + QString::number(total);
            ui->lineEdit_7->setText(totalVal);
            ui->label21->setText("No info to display.");
            ui->lineEdit_8->setText("");
        }
        else if(ui->comboBox_2->currentText() == "Driver 1"){
            for(it = map.begin(); it != map.end(); ++it){
                if(driver1.password == (it->second).driverPassword){
                    printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                    if((it->second).online){
                        printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                    }
                    else{
                        printVal += "\tCash";
                    }
                    ui->plainTextEdit_3->appendPlainText(printVal);
                    total += (it->second).price;
                }
            }
            totalVal = "$" + QString::number(total);
            ui->lineEdit_7->setText(totalVal);
            owedAmount = driver1.payWithCashTotal - driver1.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label21->setText("You owe the driver:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
            else{
                ui->label21->setText("The driver owes you:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
        }


        else if(ui->comboBox_2->currentText() == "Driver 2"){
            for(it = map.begin(); it != map.end(); ++it){
                if(driver2.password == (it->second).driverPassword){
                    printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                    if((it->second).online){
                        printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                    }
                    else{
                        printVal += "\tCash";
                    }
                    ui->plainTextEdit_3->appendPlainText(printVal);
                    total += (it->second).price;
                }
            }
            totalVal = "$" + QString::number(total);
            ui->lineEdit_7->setText(totalVal);
            owedAmount = driver2.payWithCashTotal - driver2.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label21->setText("You owe the driver:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
            else{
                ui->label21->setText("The driver owes you:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
        }
        else{
            for(it = map.begin(); it != map.end(); ++it){
                if(driver3.password == (it->second).driverPassword){
                    printVal = "OSN " + QString::number(it->first) + ": \t$" + QString::number((it->second).price);
                    if((it->second).online){
                        printVal = printVal + "\tOnline tip: $" + QString::number((it->second).onlineTipVal);
                    }
                    else{
                        printVal += "\tCash";
                    }
                    ui->plainTextEdit_3->appendPlainText(printVal);
                    total += (it->second).price;
                }
            }
            totalVal = "$" + QString::number(total);
            ui->lineEdit_7->setText(totalVal);
            owedAmount = driver3.payWithCashTotal - driver3.onlineTipTotal;
            if(owedAmount <= 0){
                owedAmount *= -1;
                ui->label21->setText("You owe the driver:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
            else{
                ui->label21->setText("The driver owes you:");
                ui->lineEdit_8->setText(QString::number(owedAmount));
            }
        }
    }
    else{
        QMessageBox::information(this, tr("TipMan"), tr("Incorrect password."));
    }
}

void Widget::adminClear(){
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->plainTextEdit_3->clear();
    ui->label21->setText("No information to display.");
}

QString Widget::name() const{
    return ui->pushButton1->text();
}
