#ifndef AMENDDATA_H
#define AMENDDATA_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "amenddata_1.h"

namespace Ui {
class amendData;
}

class amendData : public QWidget
{
    Q_OBJECT

public:
    explicit amendData(QWidget *parent = nullptr);
    ~amendData();

private slots:
    void on_searchButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::amendData *ui;
    QSqlDatabase db;
    QString type, id, name, birth, phone, email, field;
};

#endif // AMENDDATA_H
