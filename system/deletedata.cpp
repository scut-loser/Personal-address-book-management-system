#include "deletedata.h"
#include "ui_deletedata.h"

deleteData::deleteData(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deleteData)
{
    ui->setupUi(this);

    db = QSqlDatabase::database();

    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
    }
}

deleteData::~deleteData()
{
    delete ui;
}

void deleteData::on_deleteButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    QString type, id, tableName;

    QString sql = QString("SELECT type, contact_id FROM contacts WHERE name = '%1' AND phone = '%2'").arg(name).arg(phone);
    QSqlQuery query;


    if(query.exec(sql))
    {

        if(query.next())
        {

            type = query.value(0).toString();
            tableName = type + "s";
            id = query.value(1).toString();
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

    QString hint1, hint2;

    if(type == "classmate")
    {
        hint1 = "同窗之谊是前世修来的缘分，茫茫人海中相遇已属不易，别轻易让误解成为隔阂。";
        hint2 = "课桌上的三八线终会褪色，但少年时代的共同记忆永远鲜活。";
    }

    else if(type == "colleague")
    {
        hint1 = "职场风雨里共撑一把伞的情谊，比竞争榜单上的排名更值得珍藏。";
        hint2 = "办公楼里熄灭的最后一盏灯，见证过你们共同的奋斗。";
    }

    else if(type == "friend")
    {
        hint1 = "知己是生命馈赠的礼物，那些疯癫岁月里的默契千金难换。";
        hint2 = "有些话只说给懂的人听，有些人错过就再难遇见。";
    }

    else if(type == "relative")
    {
        hint1 = "年夜饭桌上少了一副碗筷，团圆照就不完整了。";
        hint2 = "祠堂里的香火传承着同一个姓氏，这是刻进DNA的联结。";
    }

    else
    {
        return;
    }

    // 创建消息框
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("望三思");
    msgBox.setText(hint1);

    // 添加确定和取消按钮
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.button(QMessageBox::Ok)->setText("删除");
    msgBox.button(QMessageBox::Cancel)->setText("取消");
    msgBox.setDefaultButton(QMessageBox::Cancel);

    // 显示模态对话框并等待用户响应
    int ret = msgBox.exec();

    // 根据用户选择做出响应
    if (ret == QMessageBox::Ok){


        sql = QString("DELETE FROM %1 where contact_id = %2;DELETE FROM contacts where contact_id = %3").arg(tableName).arg(id).arg(id);
        QStringList queryList = sql.split(";");

        bool ok = true;
        for (const QString &queryStr : queryList) {
            qDebug()<<queryStr;
            if (!queryStr.trimmed().isEmpty()) {

                if (!query.exec(queryStr.trimmed())) {
                    ok = false;
                    QMessageBox::warning(this, "警告", "删除数据失败");
                    qDebug() << "Error executing query:" << query.lastError();
                    break;
                }

            }
        }

        if(ok)
        {
            QMessageBox::information(this, "提示", "已删除");
            ui->nameLineEdit->clear();
            ui->phoneLineEdit->clear();
        }
    }

    else
    {
        QMessageBox msgBox1(this);
        msgBox1.setWindowTitle("恭喜");
        msgBox1.setText(hint2);
        msgBox1.exec();
    }
}


void deleteData::on_cancelButton_clicked()
{
    this->close();
}

