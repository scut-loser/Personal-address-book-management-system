#include "amenddata_1.h"
#include "ui_amenddata_1.h"

amendData_1::amendData_1(QString n, QString b, QString p, QString e, QString t, QString i, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::amendData_1), name(n), birth(b), phone(p), email(e), type(t), id(i)

{
    ui->setupUi(this);

    db = QSqlDatabase::database();

    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
    }



    if (type == "classmate") {
        tableName = "classmates";
        fieldName = "school_name";
        labelName = "学校名称";
    } else if (type == "colleague") {
        tableName = "colleagues";
        fieldName = "company_name";
        labelName = "单位名称";
    } else if (type == "friend") {
        tableName = "friends";
        fieldName = "meet_location";
        labelName = "认识地点";
    } else if (type == "relative") {
        tableName = "relatives";
        fieldName = "relation_title";
        labelName = "称呼";
    } else {

        return;
    }

    // 获取用户filed
    getField();

    // 设置姓名和出生日期为只读
    ui->nameLineEdit->setReadOnly(true);
    ui->birthLineEdit->setReadOnly(true);

    To_1["classmate"] = "同学";
    To_1["colleague"] = "同事";
    To_1["friend"] = "朋友";
    To_1["relative"] = "亲戚";

    To_2["同学"] = "classmate";
    To_2["同事"] = "colleague";
    To_2["朋友"] = "friend";
    To_2["亲戚"] = "relative";

    types.emplace("同学");
    types.emplace("同事");
    types.emplace("朋友");
    types.emplace("亲戚");

    // 显示
    ui->nameLineEdit->setText(name);
    ui->birthLineEdit->setText(birth);
    ui->phoneLineEdit->setText(phone);
    ui->emailLineEdit->setText(email);
    ui->typeLineEdit->setText(To_1[type]);
    ui->fieldLineEdit->setText(field);
    ui->fieldLabel->setText(labelName);

}

amendData_1::~amendData_1()
{
    delete ui;
}

bool amendData_1::isValidEmail(const QString& email)
{
    // 正则表达式解释：
    // ^[a-zA-Z0-9._%+-]+   用户名（允许字母/数字/._%+-）
    // @                     @符号
    // [a-zA-Z0-9.-]+       域名部分（允许字母/数字/.-）
    // \.[a-zA-Z]{2,}$      顶级域名（至少2个字母结尾）
    static QRegularExpression regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex.match(email).hasMatch();
}

void amendData_1::on_confirmButton_clicked()
{
    // 检测邮箱格式是否合法
    if(!isValidEmail(ui->emailLineEdit->text()))
    {
        QMessageBox::warning(this, "警告", "邮件格式错误");
        return;
    }

    // 检测关系是否合法
    if(!types.count(ui->typeLineEdit->text()))
    {
        QMessageBox::warning(this, "警告", "关系填写错误");
        return;
    }

    QString new_phone = ui->phoneLineEdit->text();
    QString new_email = ui->emailLineEdit->text();
    QString new_type = To_2[ui->typeLineEdit->text()];
    QString new_field = ui->fieldLineEdit->text();

    QSqlQuery query;
    QString sql = QString("UPDATE contacts "
                          "SET phone = '%1', email = '%2', type ='%3'"
                          " WHERE contact_id = '%4'").arg(new_phone).arg(new_email).arg(new_type).arg(id);



    query.prepare(sql);
    if(query.exec())
    {
        if(type == new_type)
        {
            sql = QString("UPDATE %1 "
                          "SET %2 = '%3' "
                          "WHERE contact_id = '%4'").arg(tableName).arg(fieldName).arg(new_field).arg(id);
            qDebug()<<sql;
            query.prepare(sql);

            if(query.exec())
            {
                updateSuccess();
            }

            else
            {
                qDebug() << "更新失败：" << query.lastError().text();
                QMessageBox::warning(this, "更新失败", "请检查更新信息是否符合规范");
            }
        }

        else
        {
            QString new_table = new_type + "s";


            sql = QString("DELETE FROM %1 WHERE contact_id = %2 ;INSERT INTO %3 values('%4', '%5') ;").arg(tableName).arg(id).arg(new_table).arg(id).arg(new_field);

            QStringList queryList = sql.split(";");


            bool ok = true;
            for (const QString &queryStr : std::as_const(queryList)) {

                if (!queryStr.trimmed().isEmpty()) {

                    if (!query.exec(queryStr.trimmed())) {
                        ok = false;
                        QMessageBox::warning(this, "警告", "修改数据失败");
                        qDebug() << "Error executing query:" << query.lastError();
                        break;
                    }

                }
            }

            if(ok)
            {
                updateSuccess();
            }
        }
    }
    else
    {
        qDebug() << "更新失败：" << query.lastError().text();
        QMessageBox::warning(this, "更新失败", "请检查更新信息是否符合规范");
    }
}

void amendData_1::updateSuccess()
{

    QMessageBox *msgBox = new QMessageBox(QMessageBox::Information, "提示", "修改数据成功", QMessageBox::Ok, this);
    connect(msgBox, &QMessageBox::finished, this, &QWidget::close); // 关闭父窗口
    msgBox->show();
}

void amendData_1::getField()
{
    QString sql = QString("SELECT %1 FROM %2 WHERE contact_id = %3").arg(fieldName).arg(tableName).arg(id);

    QSqlQuery query(sql);

    if(query.exec(sql))
    {

        if(query.next())
        {
            field = query.value(0).toString();
        }

        else
        {
            QMessageBox::warning(this, "警告", "查无此人");
            return;
        }

    }
    else {

        qDebug() << "查询失败：" << query.lastError().text();
        return;
    }
}

void amendData_1::on_cancelButton_clicked()
{
    this->close();
}

