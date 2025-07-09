#ifndef ADDDATA_1_H
#define ADDDATA_1_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDate>

namespace Ui {
class addData_1;
}

class addData_1 : public QWidget
{
    Q_OBJECT

public:
    explicit addData_1(QString t, QWidget *parent = nullptr);
    ~addData_1();

    bool isValidEmail(const QString& email);
    bool isValidDate(const QString& Date);

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::addData_1 *ui;
    QSqlDatabase db;
    QString type, tableName, fieldName, typeName, labelName, field;
};

#endif // ADDDATA_1_H
