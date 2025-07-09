#ifndef BIRTHINSPECIFIEDMONTH_H
#define BIRTHINSPECIFIEDMONTH_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include "centeraligndelegate.h"

namespace Ui {
class birthInSpecifiedMonth;
}

class birthInSpecifiedMonth : public QWidget
{
    Q_OBJECT

public:
    explicit birthInSpecifiedMonth(QWidget *parent = nullptr);
    ~birthInSpecifiedMonth();

    void refreshTable(const QString &sql);
    void adjustTableColumns(QTableView* tableView); // 列宽调整

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::birthInSpecifiedMonth *ui;
    QSqlQueryModel *model;
    QSqlDatabase db;
    QString tableName, fieldName, typeName;
};

#endif // BIRTHINSPECIFIEDMONTH_H
