/********************************************************************************
** Form generated from reading UI file 'birthinspecifiedmonth.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHINSPECIFIEDMONTH_H
#define UI_BIRTHINSPECIFIEDMONTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_birthInSpecifiedMonth
{
public:
    QLabel *label;
    QLabel *countLabel;
    QTableView *tableView;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *birthInSpecifiedMonth)
    {
        if (birthInSpecifiedMonth->objectName().isEmpty())
            birthInSpecifiedMonth->setObjectName("birthInSpecifiedMonth");
        birthInSpecifiedMonth->resize(750, 500);
        birthInSpecifiedMonth->setMinimumSize(QSize(600, 500));
        birthInSpecifiedMonth->setMaximumSize(QSize(800, 500));
        birthInSpecifiedMonth->setStyleSheet(QString::fromUtf8("#birthInSpecifiedMonth{ background:rgb(239, 249, 255); }"));
        label = new QLabel(birthInSpecifiedMonth);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 10, 131, 51));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        countLabel = new QLabel(birthInSpecifiedMonth);
        countLabel->setObjectName("countLabel");
        countLabel->setGeometry(QRect(600, 20, 91, 31));
        countLabel->setFont(font);
        tableView = new QTableView(birthInSpecifiedMonth);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 90, 721, 401));
        comboBox = new QComboBox(birthInSpecifiedMonth);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(10, 17, 91, 41));
        layoutWidget = new QWidget(birthInSpecifiedMonth);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 10, 361, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 45));
        lineEdit->setReadOnly(false);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setMinimumSize(QSize(93, 40));
        pushButton->setMaximumSize(QSize(93, 40));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(birthInSpecifiedMonth);

        QMetaObject::connectSlotsByName(birthInSpecifiedMonth);
    } // setupUi

    void retranslateUi(QWidget *birthInSpecifiedMonth)
    {
        birthInSpecifiedMonth->setWindowTitle(QCoreApplication::translate("birthInSpecifiedMonth", "\347\273\237\350\256\241\346\214\207\345\256\232\346\234\210\344\273\275\345\207\272\347\224\237\347\232\204\344\272\272\345\221\230\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("birthInSpecifiedMonth", "\347\273\237\350\256\241\344\272\272\346\225\260\357\274\232", nullptr));
        countLabel->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("birthInSpecifiedMonth", "\345\205\250\351\203\250", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("birthInSpecifiedMonth", "\345\220\214\345\255\246", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("birthInSpecifiedMonth", "\345\220\214\344\272\213", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("birthInSpecifiedMonth", "\346\234\213\345\217\213", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("birthInSpecifiedMonth", "\344\272\262\346\210\232", nullptr));

        lineEdit->setPlaceholderText(QCoreApplication::translate("birthInSpecifiedMonth", "\350\257\267\350\276\223\345\205\245\346\234\210\344\273\275", nullptr));
        pushButton->setText(QCoreApplication::translate("birthInSpecifiedMonth", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class birthInSpecifiedMonth: public Ui_birthInSpecifiedMonth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHINSPECIFIEDMONTH_H
