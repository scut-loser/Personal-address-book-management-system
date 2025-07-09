#ifndef BIRTHCONGRATULATION_H
#define BIRTHCONGRATULATION_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDate>
#include <QFile>
#include <QTableView>
#include <QProcess>
#include <QBuffer>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include "centeraligndelegate.h"

namespace Ui {
class birthCongratulation;
}

class birthCongratulation : public QWidget
{
    Q_OBJECT

public:
    explicit birthCongratulation(QWidget *parent = nullptr);
    ~birthCongratulation();

    void adjustTableColumns(QTableView* tableView); // 列宽调整
    int sendEmail(const QString &toEmail, const QString &content); // 发送电子邮件

private slots:
    void on_sendButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::birthCongratulation *ui;
    QSqlDatabase db;
    QSqlQueryModel *model; // 数据模型
    QSqlQuery query;
};

#endif // BIRTHCONGRATULATION_H
