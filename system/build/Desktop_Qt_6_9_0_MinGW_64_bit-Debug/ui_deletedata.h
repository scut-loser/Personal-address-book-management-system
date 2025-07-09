/********************************************************************************
** Form generated from reading UI file 'deletedata.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDATA_H
#define UI_DELETEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteData
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *phoneLineEdit;

    void setupUi(QWidget *deleteData)
    {
        if (deleteData->objectName().isEmpty())
            deleteData->setObjectName("deleteData");
        deleteData->resize(304, 232);
        deleteData->setMinimumSize(QSize(304, 232));
        deleteData->setMaximumSize(QSize(304, 232));
        deleteData->setStyleSheet(QString::fromUtf8("#deleteData { background:rgb(239, 249, 255); }"));
        layoutWidget = new QWidget(deleteData);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 180, 208, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        deleteButton = new QPushButton(layoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_3->addWidget(deleteButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_3->addWidget(cancelButton);

        layoutWidget1 = new QWidget(deleteData);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(40, 40, 208, 111));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        nameLineEdit = new QLineEdit(layoutWidget1);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setMinimumSize(QSize(0, 35));

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        phoneLineEdit = new QLineEdit(layoutWidget1);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setMinimumSize(QSize(0, 35));

        horizontalLayout_2->addWidget(phoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(deleteData);

        QMetaObject::connectSlotsByName(deleteData);
    } // setupUi

    void retranslateUi(QWidget *deleteData)
    {
        deleteData->setWindowTitle(QCoreApplication::translate("deleteData", "\350\257\267\350\276\223\345\205\245\350\201\224\347\263\273\344\272\272\351\241\271\347\233\256\345\222\214\347\224\265\350\257\235", nullptr));
        deleteButton->setText(QCoreApplication::translate("deleteData", "\345\210\240\351\231\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("deleteData", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("deleteData", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("deleteData", "\347\224\265\350\257\235", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteData: public Ui_deleteData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDATA_H
