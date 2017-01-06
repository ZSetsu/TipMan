#include "widget.h"
#include <QApplication>
#include <QPlainTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.setButton1("Add Order");
    w.decorate();
    w.show();

    //bool ok = false;

    return a.exec();
}
