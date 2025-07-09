#ifndef AMENDDATA_1_H
#define AMENDDATA_1_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <utility>
#include <QRegularExpression>
#include <QDate>

namespace Ui {
class amendData_1;
}

class amendData_1 : public QWidget
{
    Q_OBJECT

public:
    explicit amendData_1(QString n, QString b, QString p, QString e, QString t, QString i, QWidget *parent = nullptr);
    ~amendData_1();

    void updateSuccess();
    void getField();
    bool isValidEmail(const QString& email);

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::amendData_1 *ui;
    QString name, birth, phone, email, field, type, tableName, fieldName, labelName,id;
    QSqlDatabase db;
    std::pmr::unordered_map<QString,QString>To_1;
    std::pmr::unordered_map<QString,QString>To_2;
    std::pmr::set<QString>types;
};

#endif // AMENDDATA_1_H
