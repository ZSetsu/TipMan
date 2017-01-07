/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label6;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label7;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label0;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label1;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton1;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label3;
    QSpinBox *spinBox_2;
    QPushButton *pushButton2;
    QLabel *label8;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label10;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton4;
    QLabel *label11;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label12;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_com;
    QLineEdit *lineEdit_com;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label13;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton3;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label20;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QPlainTextEdit *plainTextEdit_3;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_com_2;
    QLineEdit *lineEdit_com_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label21;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label22;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(414, 369);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        label4 = new QLabel(tab);
        label4->setObjectName(QStringLiteral("label4"));
        QFont font;
        font.setPointSize(12);
        label4->setFont(font);

        verticalLayout_2->addWidget(label4, 0, Qt::AlignHCenter);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label6 = new QLabel(tab);
        label6->setObjectName(QStringLiteral("label6"));

        horizontalLayout_7->addWidget(label6);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(2);
        lineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(lineEdit);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_7->addWidget(comboBox);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout_2->addLayout(horizontalLayout_5);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label7 = new QLabel(tab_2);
        label7->setObjectName(QStringLiteral("label7"));

        horizontalLayout_8->addWidget(label7);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);
        lineEdit_2->setMinimumSize(QSize(0, 0));
        lineEdit_2->setMaxLength(2);
        lineEdit_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(lineEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label0 = new QLabel(tab_2);
        label0->setObjectName(QStringLiteral("label0"));

        horizontalLayout->addWidget(label0);

        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setProperty("showGroupSeparator", QVariant(false));
        spinBox->setMaximum(99999);

        horizontalLayout->addWidget(spinBox);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label1 = new QLabel(tab_2);
        label1->setObjectName(QStringLiteral("label1"));

        horizontalLayout_2->addWidget(label1);

        doubleSpinBox = new QDoubleSpinBox(tab_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(100000);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        doubleSpinBox_2 = new QDoubleSpinBox(tab_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(1e+6);

        horizontalLayout_3->addWidget(doubleSpinBox_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        pushButton1 = new QPushButton(tab_2);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));

        verticalLayout_3->addWidget(pushButton1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEdit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label3 = new QLabel(tab_2);
        label3->setObjectName(QStringLiteral("label3"));

        horizontalLayout_4->addWidget(label3);

        spinBox_2 = new QSpinBox(tab_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(99999);

        horizontalLayout_4->addWidget(spinBox_2);

        pushButton2 = new QPushButton(tab_2);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));

        horizontalLayout_4->addWidget(pushButton2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label8 = new QLabel(tab_2);
        label8->setObjectName(QStringLiteral("label8"));
        QFont font1;
        font1.setPointSize(6);
        label8->setFont(font1);

        verticalLayout_3->addWidget(label8, 0, Qt::AlignHCenter);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label10 = new QLabel(tab_3);
        label10->setObjectName(QStringLiteral("label10"));

        horizontalLayout_6->addWidget(label10);

        lineEdit_3 = new QLineEdit(tab_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);
        lineEdit_3->setMaxLength(2);
        lineEdit_3->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(lineEdit_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        pushButton4 = new QPushButton(tab_3);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));

        verticalLayout_4->addWidget(pushButton4);

        label11 = new QLabel(tab_3);
        label11->setObjectName(QStringLiteral("label11"));

        verticalLayout_4->addWidget(label11);

        plainTextEdit_2 = new QPlainTextEdit(tab_3);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label12 = new QLabel(tab_3);
        label12->setObjectName(QStringLiteral("label12"));

        horizontalLayout_9->addWidget(label12);

        lineEdit_4 = new QLineEdit(tab_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);
        lineEdit_4->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_4);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_com = new QLabel(tab_3);
        label_com->setObjectName(QStringLiteral("label_com"));

        horizontalLayout_14->addWidget(label_com);

        lineEdit_com = new QLineEdit(tab_3);
        lineEdit_com->setObjectName(QStringLiteral("lineEdit_com"));
        sizePolicy1.setHeightForWidth(lineEdit_com->sizePolicy().hasHeightForWidth());
        lineEdit_com->setSizePolicy(sizePolicy1);
        lineEdit_com->setReadOnly(true);

        horizontalLayout_14->addWidget(lineEdit_com);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label13 = new QLabel(tab_3);
        label13->setObjectName(QStringLiteral("label13"));

        horizontalLayout_10->addWidget(label13);

        lineEdit_5 = new QLineEdit(tab_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);
        lineEdit_5->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_5);


        verticalLayout_4->addLayout(horizontalLayout_10);

        pushButton3 = new QPushButton(tab_3);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));

        verticalLayout_4->addWidget(pushButton3);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label20 = new QLabel(tab_4);
        label20->setObjectName(QStringLiteral("label20"));

        horizontalLayout_11->addWidget(label20);

        lineEdit_6 = new QLineEdit(tab_4);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);
        lineEdit_6->setMaxLength(2);
        lineEdit_6->setEchoMode(QLineEdit::Password);

        horizontalLayout_11->addWidget(lineEdit_6);


        verticalLayout_5->addLayout(horizontalLayout_11);

        comboBox_2 = new QComboBox(tab_4);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        verticalLayout_5->addWidget(comboBox_2);

        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_5->addWidget(pushButton_2);

        plainTextEdit_3 = new QPlainTextEdit(tab_4);
        plainTextEdit_3->setObjectName(QStringLiteral("plainTextEdit_3"));
        plainTextEdit_3->setReadOnly(true);

        verticalLayout_5->addWidget(plainTextEdit_3);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_com_2 = new QLabel(tab_4);
        label_com_2->setObjectName(QStringLiteral("label_com_2"));

        horizontalLayout_15->addWidget(label_com_2);

        lineEdit_com_2 = new QLineEdit(tab_4);
        lineEdit_com_2->setObjectName(QStringLiteral("lineEdit_com_2"));
        sizePolicy1.setHeightForWidth(lineEdit_com_2->sizePolicy().hasHeightForWidth());
        lineEdit_com_2->setSizePolicy(sizePolicy1);

        horizontalLayout_15->addWidget(lineEdit_com_2);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label21 = new QLabel(tab_4);
        label21->setObjectName(QStringLiteral("label21"));

        horizontalLayout_13->addWidget(label21);

        lineEdit_8 = new QLineEdit(tab_4);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy1.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy1);
        lineEdit_8->setReadOnly(true);

        horizontalLayout_13->addWidget(lineEdit_8);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label22 = new QLabel(tab_4);
        label22->setObjectName(QStringLiteral("label22"));

        horizontalLayout_12->addWidget(label22);

        lineEdit_7 = new QLineEdit(tab_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);
        lineEdit_7->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_7);


        verticalLayout_5->addLayout(horizontalLayout_12);

        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_5->addWidget(pushButton_3);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QString());
        label4->setText(QApplication::translate("Widget", "label4", Q_NULLPTR));
        label6->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Tab 1", Q_NULLPTR));
        label7->setText(QApplication::translate("Widget", "label7", Q_NULLPTR));
        label0->setText(QApplication::translate("Widget", "label0", Q_NULLPTR));
        label1->setText(QApplication::translate("Widget", "label1", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Widget", "CheckBox", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        label3->setText(QApplication::translate("Widget", "label3", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        label8->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", Q_NULLPTR));
        label10->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton4->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        label11->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label12->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_com->setText(QApplication::translate("Widget", "5% Commission:", Q_NULLPTR));
        label13->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "Page", Q_NULLPTR));
        label20->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        label_com_2->setText(QApplication::translate("Widget", "5% Commission", Q_NULLPTR));
        label21->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label22->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Widget", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
