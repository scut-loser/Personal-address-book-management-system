/********************************************************************************
** Form generated from reading UI file 'amenddata.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMENDDATA_H
#define UI_AMENDDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_amendData
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *phoneLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *searchButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *amendData)
    {
        if (amendData->objectName().isEmpty())
            amendData->setObjectName("amendData");
        amendData->resize(317, 206);
        amendData->setMinimumSize(QSize(317, 206));
        amendData->setMaximumSize(QSize(317, 206));
        amendData->setStyleSheet(QString::fromUtf8("#amendData { background:rgb(239, 249, 255); }"));
        layoutWidget = new QWidget(amendData);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 50, 208, 63));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        phoneLineEdit = new QLineEdit(layoutWidget);
        phoneLineEdit->setObjectName("phoneLineEdit");

        horizontalLayout_2->addWidget(phoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(amendData);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 140, 195, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchButton = new QPushButton(layoutWidget1);
        searchButton->setObjectName("searchButton");

        horizontalLayout_3->addWidget(searchButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_3->addWidget(cancelButton);


        retranslateUi(amendData);

        QMetaObject::connectSlotsByName(amendData);
    } // setupUi

    void retranslateUi(QWidget *amendData)
    {
        amendData->setWindowTitle(QCoreApplication::translate("amendData", "\350\257\267\350\276\223\345\205\245\350\201\224\347\263\273\344\272\272\345\247\223\345\220\215\345\222\214\347\224\265\350\257\235", nullptr));
        label->setText(QCoreApplication::translate("amendData", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("amendData", "\347\224\265\350\257\235", nullptr));
        searchButton->setText(QCoreApplication::translate("amendData", "\346\237\245\350\257\242", nullptr));
        cancelButton->setText(QCoreApplication::translate("amendData", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class amendData: public Ui_amendData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMENDDATA_H
