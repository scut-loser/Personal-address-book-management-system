#include "amenddata.h"
#include "ui_amenddata.h"

amendData::amendData(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::amendData)
{
    ui->setupUi(this);
}

amendData::~amendData()
{
    delete ui;
}

void amendData::on_searchButton_clicked()
{
    name = ui->nameLineEdit->text();
    phone = ui->phoneLineEdit->text();

    // 获取关系、id、生日和邮箱
    QString sql = QString("SELECT type, contact_id, birthdate, email FROM contacts WHERE name = '%1' AND phone = '%2'").arg(name).arg(phone);
    QSqlQuery query;


    if(query.exec(sql))
    {

        if(query.next())
        {

            type = query.value(0).toString();
            id = query.value(1).toString();
            birth = query.value(2).toString();
            email = query.value(3).toString();
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

    amendData_1 *amend_D_1 = new amendData_1(name, birth, phone, email, type, id);
    amend_D_1->setAttribute(Qt::WA_DeleteOnClose);
    amend_D_1->show();
}


void amendData::on_cancelButton_clicked()
{
    this->close();
}

