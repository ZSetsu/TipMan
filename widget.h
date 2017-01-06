#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <map>

namespace Ui {
class Widget;
}

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
    void handleButton();
private:
    Ui::Widget *ui;
    //typedef pair<int, double> value_type;
    std::map<int, double> map;
    //int orderCount = 1;
};

#endif // WIDGET_H
