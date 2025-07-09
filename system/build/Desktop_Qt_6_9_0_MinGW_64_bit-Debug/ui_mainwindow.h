/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addAction;
    QAction *amendAction;
    QAction *deleteAction;
    QAction *namesortSAction;
    QAction *namesortJAction;
    QAction *birthsortSAction;
    QAction *birthsortJAction;
    QAction *birthReminding;
    QAction *birthInMonth;
    QWidget *centralwidget;
    QTableView *tableView;
    QListWidget *listWidget;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(920, 608);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(869, 608));
        MainWindow->setMaximumSize(QSize(1000, 608));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/PC/Pictures/\347\264\240\346\235\220/\351\200\232\350\256\257\345\275\225.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow > QWidget { background:rgb(239, 248, 255); }"));
        addAction = new QAction(MainWindow);
        addAction->setObjectName("addAction");
        amendAction = new QAction(MainWindow);
        amendAction->setObjectName("amendAction");
        deleteAction = new QAction(MainWindow);
        deleteAction->setObjectName("deleteAction");
        namesortSAction = new QAction(MainWindow);
        namesortSAction->setObjectName("namesortSAction");
        namesortJAction = new QAction(MainWindow);
        namesortJAction->setObjectName("namesortJAction");
        birthsortSAction = new QAction(MainWindow);
        birthsortSAction->setObjectName("birthsortSAction");
        birthsortJAction = new QAction(MainWindow);
        birthsortJAction->setObjectName("birthsortJAction");
        birthReminding = new QAction(MainWindow);
        birthReminding->setObjectName("birthReminding");
        birthInMonth = new QAction(MainWindow);
        birthInMonth->setObjectName("birthInMonth");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(130, 100, 781, 461));
        QFont font;
        font.setPointSize(10);
        tableView->setFont(font);
        tableView->setStyleSheet(QString::fromUtf8(""));
        listWidget = new QListWidget(centralwidget);
        QFont font1;
        font1.setPointSize(15);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font1);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font1);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font1);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setFont(font1);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget);
        __qlistwidgetitem4->setFont(font1);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 160, 91, 311));
        listWidget->setStyleSheet(QString::fromUtf8(""));
        listWidget->setSpacing(15);
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(170, 30, 570, 61));
        sizePolicy.setHeightForWidth(searchLineEdit->sizePolicy().hasHeightForWidth());
        searchLineEdit->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(14);
        searchLineEdit->setFont(font2);
        searchLineEdit->setStyleSheet(QString::fromUtf8("border: 1px solid #A0A0A0;\n"
"border-radius: 10px;      \n"
""));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(770, 35, 91, 51));
        sizePolicy.setHeightForWidth(searchButton->sizePolicy().hasHeightForWidth());
        searchButton->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Nirmala UI")});
        font3.setPointSize(13);
        searchButton->setFont(font3);
        searchButton->setStyleSheet(QString::fromUtf8("border-radius: 20px;\n"
"background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 920, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(addAction);
        menu->addAction(amendAction);
        menu->addAction(deleteAction);
        menu_2->addAction(namesortSAction);
        menu_2->addAction(namesortJAction);
        menu_2->addAction(birthsortSAction);
        menu_2->addAction(birthsortJAction);
        menu_3->addAction(birthReminding);
        menu_3->addAction(birthInMonth);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\252\344\272\272\351\200\232\344\277\241\345\275\225\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        addAction->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\201\224\347\263\273\344\272\272", nullptr));
        amendAction->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\201\224\347\263\273\344\272\272", nullptr));
        deleteAction->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\201\224\347\263\273\344\272\272", nullptr));
        namesortSAction->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\247\223\345\220\215\345\215\207\345\272\217", nullptr));
        namesortJAction->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\247\223\345\220\215\351\231\215\345\272\217", nullptr));
        birthsortSAction->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\207\272\347\224\237\346\227\245\346\234\237\345\215\207\345\272\217", nullptr));
        birthsortJAction->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\207\272\347\224\237\346\227\245\346\234\237\351\231\215\345\272\217", nullptr));
        birthReminding->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\227\245\346\217\220\351\206\222", nullptr));
        birthInMonth->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241\346\234\210\344\273\275\344\272\272\346\225\260", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\203\250", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\220\214\345\255\246", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\345\220\214\344\272\213", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\234\213\345\217\213", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "\344\272\262\346\210\232", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\202\250\350\246\201\346\237\245\350\257\242\347\232\204\345\247\223\345\220\215", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\222\345\272\217\346\226\271\345\274\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
