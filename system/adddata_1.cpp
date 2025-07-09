#include "adddata_1.h"
#include "ui_adddata_1.h"

addData_1::addData_1(QString t, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addData_1), type(t)
{
    ui->setupUi(this);

    // 连接数据库
    db = QSqlDatabase::database();

    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
    }


    if (type == "同学") {
        tableName = "classmates";
        fieldName = "school_name";
        typeName = "classmate";
        labelName = "学校名称";
    } else if (type == "同事") {
        tableName = "colleagues";
        fieldName = "company_name";
        typeName = "colleague";
        labelName = "单位名称";
    } else if (type == "朋友") {
        tableName = "friends";
        fieldName = "meet_location";
        typeName = "friend";
        labelName = "认识地点";
    } else if (type == "亲戚") {
        tableName = "relatives";
        fieldName = "relation_title";
        typeName = "relative";
        labelName = "称呼";
    } else {
        return;
    }

    ui->fieldLabel->setText(labelName);

}

addData_1::~addData_1()
{
    delete ui;
}

bool addData_1::isValidEmail(const QString& email)
{
    // 正则表达式解释：
    // ^[a-zA-Z0-9._%+-]+   用户名（允许字母/数字/._%+-）
    // @                     @符号
    // [a-zA-Z0-9.-]+       域名部分（允许字母/数字/.-）
    // \.[a-zA-Z]{2,}$      顶级域名（至少2个字母结尾）
    static QRegularExpression regex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return regex.match(email).hasMatch();
}

bool addData_1::isValidDate(const QString& date)
{
    // 正则表达式匹配：YYYY-M-D 或 YYYY-MM-DD 格式
    static QRegularExpression regex("^(\\d{4})-(\\d{1,2})-(\\d{1,2})$");
    QRegularExpressionMatch match = regex.match(date);

    if (match.hasMatch()) {
        // 提取年、月、日并补全前导零
        QString year = match.captured(1);
        QString month = match.captured(2).rightJustified(2, '0');
        QString day = match.captured(3).rightJustified(2, '0');

        QDate date = QDate::fromString(year + "-" + month + "-" + day, "yyyy-MM-dd");

        if (date.isValid()) {
            return true;
        } else {
            return false;
        }

    } else {
        return false;
    }
}

void addData_1::on_confirmButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString birth = ui->birthLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString field = ui->fieldLineEdit->text();

    // 检测出生日期格式是否合法
    if(!isValidDate(birth))
    {
        QMessageBox::warning(this, "警告", "出生日期格式错误");
        return;
    }

    // 检测邮箱格式是否合法
    if(!isValidEmail(email))
    {
        QMessageBox::warning(this, "警告", "邮件格式错误");
        return;
    }

    // 插入一条数据
    QString sql = QString("insert into contacts(name, birthdate, phone, email, type) values ('%1', '%2','%3','%4','%5');"
                          "set @last_id = last_insert_id();"
                          "insert into %6(contact_id, %7) values (@last_id,'%8');"
                          ).arg(name).arg(birth).arg(phone).arg(email).arg(typeName).arg(tableName).arg(fieldName).arg(field);

    QStringList queryList = sql.split(";");


    bool ok = true;
    for (const QString &queryStr : queryList) {
        if (!queryStr.trimmed().isEmpty()) {

            QSqlQuery query;
            if (!query.exec(queryStr.trimmed())) {
                ok = false;
                QMessageBox::warning(this, "警告", "添加数据失败");
                qDebug() << "Error executing query:" << query.lastError();
                break;
            }

        }
    }

    if(ok)
    {
        QMessageBox::information(this, "提示", "添加数据成功");
    }

    ui->nameLineEdit->clear();
    ui->birthLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->emailLineEdit->clear();
    ui->fieldLineEdit->clear();
}


void addData_1::on_cancelButton_clicked()
{
    this->close();
}

