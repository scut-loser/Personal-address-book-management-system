#ifndef DELETEDATA_H
#define DELETEDATA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class deleteData;
}

class deleteData : public QWidget
{
    Q_OBJECT

public:
    explicit deleteData(QWidget *parent = nullptr);
    ~deleteData();

private slots:
    void on_deleteButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::deleteData *ui;
    QSqlDatabase db;
};

#endif // DELETEDATA_H
