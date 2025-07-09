/********************************************************************************
** Form generated from reading UI file 'birthcongratulation.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIRTHCONGRATULATION_H
#define UI_BIRTHCONGRATULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_birthCongratulation
{
public:
    QLabel *label;
    QTableView *tableView;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *sendButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *birthCongratulation)
    {
        if (birthCongratulation->objectName().isEmpty())
            birthCongratulation->setObjectName("birthCongratulation");
        birthCongratulation->resize(846, 408);
        birthCongratulation->setMinimumSize(QSize(846, 408));
        birthCongratulation->setMaximumSize(QSize(846, 408));
        birthCongratulation->setStyleSheet(QString::fromUtf8("#birthCongratulation{ background:rgb(239, 249, 255); }"));
        label = new QLabel(birthCongratulation);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 121, 41));
        tableView = new QTableView(birthCongratulation);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 70, 711, 271));
        layoutWidget = new QWidget(birthCongratulation);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 359, 594, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(400);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName("sendButton");

        horizontalLayout->addWidget(sendButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(birthCongratulation);

        QMetaObject::connectSlotsByName(birthCongratulation);
    } // setupUi

    void retranslateUi(QWidget *birthCongratulation)
    {
        birthCongratulation->setWindowTitle(QCoreApplication::translate("birthCongratulation", "\350\277\221\346\234\237\347\224\237\346\227\245", nullptr));
        label->setText(QCoreApplication::translate("birthCongratulation", "<html><head/><body><p><span style=\" font-size:14pt;\">5\345\244\251\345\206\205\347\224\237\346\227\245\357\274\232</span></p></body></html>", nullptr));
        sendButton->setText(QCoreApplication::translate("birthCongratulation", "\345\217\221\351\200\201\347\245\235\350\264\272\351\202\256\344\273\266", nullptr));
        cancelButton->setText(QCoreApplication::translate("birthCongratulation", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class birthCongratulation: public Ui_birthCongratulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIRTHCONGRATULATION_H
