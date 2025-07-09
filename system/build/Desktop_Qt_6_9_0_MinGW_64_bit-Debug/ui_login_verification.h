/********************************************************************************
** Form generated from reading UI file 'login_verification.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_VERIFICATION_H
#define UI_LOGIN_VERIFICATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Verification
{
public:
    QLabel *label_2;
    QPushButton *sendButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Login_Verification)
    {
        if (Login_Verification->objectName().isEmpty())
            Login_Verification->setObjectName("Login_Verification");
        Login_Verification->resize(374, 252);
        Login_Verification->setMinimumSize(QSize(374, 252));
        Login_Verification->setMaximumSize(QSize(374, 252));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/PC/Pictures/\347\264\240\346\235\220/\351\222\245\345\214\231.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login_Verification->setWindowIcon(icon);
        Login_Verification->setStyleSheet(QString::fromUtf8("#Login_Verification{background-color: rgb(254, 255, 248);}\n"
""));
        label_2 = new QLabel(Login_Verification);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 20, 141, 61));
        sendButton = new QPushButton(Login_Verification);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(317, 97, 51, 28));
        widget = new QWidget(Login_Verification);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 90, 251, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(Login_Verification);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(70, 160, 228, 30));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(40);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        confirmButton = new QPushButton(widget1);
        confirmButton->setObjectName("confirmButton");

        horizontalLayout_2->addWidget(confirmButton);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_2->addWidget(cancelButton);


        retranslateUi(Login_Verification);

        QMetaObject::connectSlotsByName(Login_Verification);
    } // setupUi

    void retranslateUi(QWidget *Login_Verification)
    {
        Login_Verification->setWindowTitle(QCoreApplication::translate("Login_Verification", "\347\231\273\345\275\225\351\252\214\350\257\201", nullptr));
        label_2->setText(QCoreApplication::translate("Login_Verification", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        sendButton->setText(QCoreApplication::translate("Login_Verification", "\345\217\221\351\200\201", nullptr));
        label->setText(QCoreApplication::translate("Login_Verification", "<html><head/><body><p><span style=\" font-size:11pt;\">\351\252\214\350\257\201\347\240\201</span></p></body></html>", nullptr));
        confirmButton->setText(QCoreApplication::translate("Login_Verification", "\347\241\256\350\256\244", nullptr));
        cancelButton->setText(QCoreApplication::translate("Login_Verification", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_Verification: public Ui_Login_Verification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_VERIFICATION_H
