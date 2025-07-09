#include "mainwindow.h"
#include "login_verification.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //qDebug()<<QSqlDatabase::drivers();
    Login_Verification L_V;
    L_V.show();
    // MainWindow w;
    // w.show();
    return a.exec();
}
