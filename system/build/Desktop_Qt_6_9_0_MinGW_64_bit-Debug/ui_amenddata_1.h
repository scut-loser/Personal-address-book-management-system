/********************************************************************************
** Form generated from reading UI file 'amenddata_1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMENDDATA_1_H
#define UI_AMENDDATA_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_amendData_1
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *birthLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *phoneLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *typeLineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *fieldLabel;
    QLineEdit *fieldLineEdit;

    void setupUi(QWidget *amendData_1)
    {
        if (amendData_1->objectName().isEmpty())
            amendData_1->setObjectName("amendData_1");
        amendData_1->resize(403, 332);
        amendData_1->setMinimumSize(QSize(403, 332));
        amendData_1->setMaximumSize(QSize(403, 332));
        amendData_1->setStyleSheet(QString::fromUtf8("#amendData_1 { background:rgb(239, 249, 255); }"));
        layoutWidget = new QWidget(amendData_1);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 270, 328, 30));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(140);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(layoutWidget);
        confirmButton->setObjectName("confirmButton");

        horizontalLayout_4->addWidget(confirmButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_4->addWidget(cancelButton);

        layoutWidget1 = new QWidget(amendData_1);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(30, 30, 331, 221));
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
        nameLineEdit->setMaxLength(32767);

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        birthLineEdit = new QLineEdit(layoutWidget1);
        birthLineEdit->setObjectName("birthLineEdit");

        horizontalLayout_2->addWidget(birthLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        phoneLineEdit = new QLineEdit(layoutWidget1);
        phoneLineEdit->setObjectName("phoneLineEdit");

        horizontalLayout_3->addWidget(phoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        emailLineEdit = new QLineEdit(layoutWidget1);
        emailLineEdit->setObjectName("emailLineEdit");

        horizontalLayout_5->addWidget(emailLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        typeLineEdit = new QLineEdit(layoutWidget1);
        typeLineEdit->setObjectName("typeLineEdit");

        horizontalLayout_6->addWidget(typeLineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        fieldLabel = new QLabel(layoutWidget1);
        fieldLabel->setObjectName("fieldLabel");

        horizontalLayout_7->addWidget(fieldLabel);

        fieldLineEdit = new QLineEdit(layoutWidget1);
        fieldLineEdit->setObjectName("fieldLineEdit");

        horizontalLayout_7->addWidget(fieldLineEdit);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(amendData_1);

        QMetaObject::connectSlotsByName(amendData_1);
    } // setupUi

    void retranslateUi(QWidget *amendData_1)
    {
        amendData_1->setWindowTitle(QCoreApplication::translate("amendData_1", "\346\233\264\346\226\260\344\277\241\346\201\257", nullptr));
        confirmButton->setText(QCoreApplication::translate("amendData_1", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("amendData_1", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("amendData_1", "\345\247\223\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("amendData_1", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("amendData_1", "\347\224\265\350\257\235", nullptr));
        label_4->setText(QCoreApplication::translate("amendData_1", "\351\202\256\347\256\261", nullptr));
        label_5->setText(QCoreApplication::translate("amendData_1", "\345\205\263\347\263\273", nullptr));
        fieldLabel->setText(QCoreApplication::translate("amendData_1", "\346\234\211\351\227\256\351\242\230\345\223\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class amendData_1: public Ui_amendData_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMENDDATA_1_H
