#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <map>
#include <QMessageBox>

namespace Ui {
class Widget;
}

struct Driver{
    bool filled = false;
    int driverNum = 0;
    double onlineTipTotal = 0;
    double payWithCashTotal = 0;
    QString password = "null";
};

struct Order{
    bool online = false;
    double onlineTipVal = 0;
    double price;
    QString driverPassword;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //void setButton1(const QString &name);
    void decorate();
    QString name() const;
private slots:
    void startCashButton();
    void handleButton();
    void deleteOSN();
    void showInfo();
    void clearInfo();
private:
    Ui::Widget *ui;
    std::map<int, Order> map;
    std::map<int, Order>::iterator it;

    QString printVal;
    QString driverPass;
    int startingCash = 0;
    int pdriverNum = 0;
    int orderCount = 1;

    Driver driver1;
    Driver driver2;
    Driver driver3;

};

#endif // WIDGET_H
