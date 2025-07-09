#include "birthcongratulation.h"
#include "ui_birthcongratulation.h"

birthCongratulation::birthCongratulation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::birthCongratulation)
{
    ui->setupUi(this);

    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);    // 绑定模型到TableView

    db = QSqlDatabase::database();


    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
        return;
    }

    query = QSqlQuery(db);

    // QString sql = R"(SELECT name, birthdate, phone, email
    //               FROM contacts
    //                   WHERE
    //                       CASE
    //                           WHEN
    //                           DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR) >= CURDATE()
    //               THEN
    //                   DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR)
    //               ELSE
    //                   DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) + 1 - YEAR(birthdate) YEAR)
    //               END
    //                   BETWEEN CURDATE() AND DATE_ADD(CURDATE(), INTERVAL 5 DAY);)";

    query.exec("SET lc_time_names = 'zh_CN';");

    QString sql = R"(SELECT
    name AS 姓名,
    birthdate AS 出生日期,
    DATE_FORMAT(
        CASE
            WHEN DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR) >= CURDATE()
                THEN DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR)
            ELSE DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) + 1 - YEAR(birthdate) YEAR)
        END,
        '%W'
    ) AS 未来五天内生日时间,  -- 输出中文星期几（如 "星期一"）
    phone AS 电话,
    email AS 邮箱
FROM contacts
WHERE
    CASE
        WHEN DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR) >= CURDATE()
            THEN DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) - YEAR(birthdate) YEAR)
        ELSE DATE_ADD(birthdate, INTERVAL YEAR(CURDATE()) + 1 - YEAR(birthdate) YEAR)
    END BETWEEN CURDATE() AND DATE_ADD(CURDATE(), INTERVAL 5 DAY);)";


    query.prepare(sql);

    if (query.exec()) {
        // 将结果展示到 TableView
        model->setQuery(sql);

        // 调整列宽
        adjustTableColumns(ui->tableView);

        // 使数据居中对齐
        ui->tableView->setItemDelegate(new CenterAlignDelegate(ui->tableView));

    } else {
        qDebug() << "查询失败：" << query.lastError().text();
    }

}

birthCongratulation::~birthCongratulation()
{
    delete ui;
}

// 列宽调整
void birthCongratulation::adjustTableColumns(QTableView* tableView) {
    if (!tableView || !tableView->model()) return;

    QHeaderView* header = tableView->horizontalHeader();
    int viewWidth = tableView->viewport()->width(); // 排除滚动条后的有效宽度
    int columnCount = tableView->model()->columnCount();

    if (columnCount == 0) return;

    // 计算每列宽度并分配余数
    int baseWidth = viewWidth / columnCount;
    int remainder = viewWidth % columnCount;

    // 禁止用户手动调整列宽
    //header->setSectionResizeMode(QHeaderView::Fixed);

    for (int col = 0; col < columnCount; ++col) {
        int width = baseWidth + (col < remainder ? 1 : 0);
        tableView->setColumnWidth(col, width);
    }
}

void birthCongratulation::on_sendButton_clicked()
{
    int count = 0;

    // 遍历结果并处理
    while (query.next()) {
        QString name = query.value("姓名").toString();
        QString email = query.value("邮箱").toString();

        qDebug()<<name<<" "<<email;

        QString buffer; // 创建一个QString用于存储数据
        QTextStream out(&buffer); // 将QTextStream关联到该字符串

        out << "亲爱的" << name <<":"<< "\n";
        out << "         祝生日快乐，健康幸福。\n";
        out << "                      Yijie Li";

        int flag = sendEmail(email, buffer);
        if (flag == 0)
        {
            count++;
            continue;
        }
        else if(flag == -1 || flag == -2)
        {

            QMessageBox::warning(this, "警告", "请检查第" + QString::number(count + 1) + "位收件人邮件地址是否有误");
            return;
        }
        else
        {
            QMessageBox::warning(this, "警告", "发生未知错误！！！");
            return;
        }

    }

    QMessageBox::information(this, "提示", "邮件发送成功！");

}

int birthCongratulation::sendEmail(const QString &toEmail, const QString &content) {
    QProcess process;
    QString scriptPath = QCoreApplication::applicationDirPath() + "/EmailSender_QFile_2.py";
    QStringList arguments;
    arguments << scriptPath << "--to" << toEmail << "--content" << content;

    process.start("python", arguments);
    process.waitForFinished(5000);


    QString output = process.readAllStandardOutput();
    if (output.contains("success")) {
        qDebug() << "邮件发送成功";
        return 0;
    } else if (output.contains("收件人地址不存在")) {  // 捕获特定错误
        qDebug() << "错误：收件人地址无效";
        return -1;
    } else if (output.contains("SMTP服务器返回错误")) {
        qDebug() << "SMTP协议错误：" << output;
        return -2;
    } else {
        qDebug() << "未知错误：" << output;
        return -3;
    }
}

void birthCongratulation::on_cancelButton_clicked()
{
    this->close();
}

