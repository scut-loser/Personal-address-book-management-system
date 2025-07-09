/********************************************************************************
** Form generated from reading UI file 'adddata_1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATA_1_H
#define UI_ADDDATA_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addData_1
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *birthLabel;
    QLineEdit *birthLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *phoneLabel;
    QLineEdit *phoneLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *fieldLabel;
    QLineEdit *fieldLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *addData_1)
    {
        if (addData_1->objectName().isEmpty())
            addData_1->setObjectName("addData_1");
        addData_1->resize(400, 300);
        addData_1->setMinimumSize(QSize(400, 300));
        addData_1->setMaximumSize(QSize(400, 300));
        addData_1->setStyleSheet(QString::fromUtf8("#addData_1 { background:rgb(239, 249, 255); }"));
        layoutWidget = new QWidget(addData_1);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 351, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nameLabel = new QLabel(layoutWidget);
        nameLabel->setObjectName("nameLabel");

        horizontalLayout->addWidget(nameLabel);

        nameLineEdit = new QLineEdit(layoutWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        horizontalLayout->addWidget(nameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        birthLabel = new QLabel(layoutWidget);
        birthLabel->setObjectName("birthLabel");

        horizontalLayout_2->addWidget(birthLabel);

        birthLineEdit = new QLineEdit(layoutWidget);
        birthLineEdit->setObjectName("birthLineEdit");

        horizontalLayout_2->addWidget(birthLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        phoneLabel = new QLabel(layoutWidget);
        phoneLabel->setObjectName("phoneLabel");

        horizontalLayout_3->addWidget(phoneLabel);

        phoneLineEdit = new QLineEdit(layoutWidget);
        phoneLineEdit->setObjectName("phoneLineEdit");

        horizontalLayout_3->addWidget(phoneLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName("emailLabel");

        horizontalLayout_4->addWidget(emailLabel);

        emailLineEdit = new QLineEdit(layoutWidget);
        emailLineEdit->setObjectName("emailLineEdit");

        horizontalLayout_4->addWidget(emailLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        fieldLabel = new QLabel(layoutWidget);
        fieldLabel->setObjectName("fieldLabel");

        horizontalLayout_5->addWidget(fieldLabel);

        fieldLineEdit = new QLineEdit(layoutWidget);
        fieldLineEdit->setObjectName("fieldLineEdit");

        horizontalLayout_5->addWidget(fieldLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(addData_1);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(50, 260, 278, 30));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(90);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(layoutWidget1);
        confirmButton->setObjectName("confirmButton");

        horizontalLayout_6->addWidget(confirmButton);

        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_6->addWidget(cancelButton);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 3);

        retranslateUi(addData_1);

        QMetaObject::connectSlotsByName(addData_1);
    } // setupUi

    void retranslateUi(QWidget *addData_1)
    {
        addData_1->setWindowTitle(QCoreApplication::translate("addData_1", "\350\257\267\345\241\253\345\206\231\350\201\224\347\263\273\344\272\272\344\277\241\346\201\257", nullptr));
        nameLabel->setText(QCoreApplication::translate("addData_1", "\345\247\223\345\220\215", nullptr));
        nameLineEdit->setText(QString());
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("addData_1", "\350\257\267\350\276\223\345\205\245\346\213\274\351\237\263\346\210\226\350\213\261\346\226\207", nullptr));
        birthLabel->setText(QCoreApplication::translate("addData_1", "\345\207\272\347\224\237\346\227\245\346\234\237", nullptr));
        birthLineEdit->setText(QString());
        birthLineEdit->setPlaceholderText(QCoreApplication::translate("addData_1", "\350\257\267\350\276\223\345\205\245\347\261\273\344\274\274\342\200\2342006-09-02\342\200\235\347\232\204\346\227\245\346\234\237\346\240\274\345\274\217", nullptr));
        phoneLabel->setText(QCoreApplication::translate("addData_1", "\347\224\265\350\257\235", nullptr));
        phoneLineEdit->setText(QString());
        phoneLineEdit->setPlaceholderText(QCoreApplication::translate("addData_1", "\346\234\200\345\244\247\344\270\215\350\266\205\350\277\20720\344\275\215", nullptr));
        emailLabel->setText(QCoreApplication::translate("addData_1", "\351\202\256\347\256\261", nullptr));
        emailLineEdit->setText(QString());
        fieldLabel->setText(QCoreApplication::translate("addData_1", "\346\234\211\351\227\256\351\242\230\345\223\246", nullptr));
        fieldLineEdit->setText(QString());
        confirmButton->setText(QCoreApplication::translate("addData_1", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("addData_1", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addData_1: public Ui_addData_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATA_1_H
