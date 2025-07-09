/********************************************************************************
** Form generated from reading UI file 'adddata.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATA_H
#define UI_ADDDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addData
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *addData)
    {
        if (addData->objectName().isEmpty())
            addData->setObjectName("addData");
        addData->resize(348, 204);
        addData->setMinimumSize(QSize(348, 204));
        addData->setMaximumSize(QSize(348, 204));
        addData->setStyleSheet(QString::fromUtf8("#addData { background:rgb(239, 249, 255); }"));
        label = new QLabel(addData);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 171, 51));
        comboBox = new QComboBox(addData);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(100, 80, 151, 31));
        layoutWidget = new QWidget(addData);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 130, 248, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(60);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(layoutWidget);
        confirmButton->setObjectName("confirmButton");

        horizontalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(addData);

        QMetaObject::connectSlotsByName(addData);
    } // setupUi

    void retranslateUi(QWidget *addData)
    {
        addData->setWindowTitle(QCoreApplication::translate("addData", "\350\257\267\351\200\211\346\213\251\346\267\273\345\212\240\350\201\224\347\263\273\344\272\272\347\261\273\345\210\253", nullptr));
        label->setText(QCoreApplication::translate("addData", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\201\224\347\263\273\344\272\272\347\261\273\345\210\253\357\274\232</span></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("addData", "\345\220\214\345\255\246", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("addData", "\345\220\214\344\272\213", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("addData", "\346\234\213\345\217\213", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("addData", "\344\272\262\346\210\232", nullptr));

        confirmButton->setText(QCoreApplication::translate("addData", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("addData", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addData: public Ui_addData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATA_H
