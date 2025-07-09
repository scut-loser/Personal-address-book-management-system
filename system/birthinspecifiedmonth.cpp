#include "birthinspecifiedmonth.h"
#include "ui_birthinspecifiedmonth.h"

birthInSpecifiedMonth::birthInSpecifiedMonth(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::birthInSpecifiedMonth)
{
    ui->setupUi(this);

    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);    // 绑定模型到TableView

    db = QSqlDatabase::database();

    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
    }

    // 使数据居中对齐
    ui->tableView->setItemDelegate(new CenterAlignDelegate(ui->tableView));


    tableName = "contacts";
    refreshTable("SELECT name AS 姓名, birthdate AS 出生日期, phone AS 电话, email AS 邮箱 FROM contacts");

    // 输入框关联回车键
    connect(ui->lineEdit, &QLineEdit::returnPressed, this, &birthInSpecifiedMonth::on_pushButton_clicked);

}

birthInSpecifiedMonth::~birthInSpecifiedMonth()
{
    delete ui;
}

// 列宽调整
void birthInSpecifiedMonth::adjustTableColumns(QTableView* tableView) {
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

// 刷新TableView数据
void birthInSpecifiedMonth::refreshTable(const QString &sql) {

    ui->tableView->setModel(model);
    model->setQuery(sql);  // 执行SQL查询
    if (model->lastError().isValid()) {
        qDebug() << "查询错误：" << model->lastError().text();
    }

    // 统计人数
    int rowNums = ui->tableView->model()->rowCount();
    ui->countLabel->setText(QString::number(rowNums));

    adjustTableColumns(ui->tableView);
}

void birthInSpecifiedMonth::on_comboBox_activated(int index)
{
    ui->countLabel->clear();

    QString type = ui->comboBox->currentText();

    // 根据类型选择子表和字段
    if (type == "同学") {
        tableName = "classmates";
        fieldName = "school_name AS 学校名称";
        typeName = "classmate";
    } else if (type == "同事") {
        tableName = "colleagues";
        fieldName = "company_name AS 单位名称";
        typeName = "colleague";
    } else if (type == "朋友") {
        tableName = "friends";
        fieldName = "meet_location AS 认识地点";
        typeName = "friend";
    } else if (type == "亲戚") {
        tableName = "relatives";
        fieldName = "relation_title AS 称呼";
        typeName = "relative";
    } else {

        tableName = "contacts";
        refreshTable("SELECT name AS 姓名, birthdate AS 出生日期, phone AS 电话, email AS 邮箱 FROM contacts");
        return;
    }

    // 构建动态SQL
    QString sql = QString(
                      "SELECT c.name AS 姓名, c.birthdate AS 出生日期, c.phone AS 电话, c.email AS 邮箱, %1 "
                      "FROM contacts c "
                      "JOIN %2 ON c.contact_id = %3.contact_id "
                      "WHERE c.type = '%4'"
                      ).arg(fieldName).arg(tableName).arg(tableName).arg(typeName);

    refreshTable(sql);
}


void birthInSpecifiedMonth::on_pushButton_clicked()
{
    bool ok;
    QString month = ui->lineEdit->text();
    int value = month.toInt(&ok);

    ui->lineEdit->clear();

    if(!(ok && value >=1 && value <=12))
    {

        QMessageBox::warning(this, "警告", "请输入1~12的数字");
        return;
    }

    QSqlQuery query;

    if(tableName == "contacts")
    {
        QString sql = "SELECT name AS 姓名, birthdate AS 出生日期, phone AS 电话, email AS 邮箱 FROM contacts WHERE MONTH(birthdate) = ?";
        query.prepare(sql);
        query.addBindValue(month);

        if (query.exec()) {
            // 将结果展示到 TableView
            model->setQuery(std::move(query));

            // 统计人数
            int rowNums = ui->tableView->model()->rowCount();
            ui->countLabel->setText(QString::number(rowNums));
        } else {
            qDebug() << "查询失败：" << query.lastError().text();
        }

    }

    else
    {
        QString sql = QString(
                          "SELECT c.name AS 姓名, c.birthdate AS 出生日期, c.phone AS 电话, c.email AS 邮箱, %1 "
                          "FROM contacts c "
                          "JOIN %2 ON c.contact_id = %3.contact_id "
                          "WHERE c.type = '%4' AND MONTH(birthdate) = ?"
                          ).arg(fieldName).arg(tableName).arg(tableName).arg(typeName);

        query.prepare(sql);
        query.addBindValue(month);

        if (query.exec()) {
            // 将结果展示到 TableView
            model->setQuery(std::move(query));

            // 统计人数
            int rowNums = ui->tableView->model()->rowCount();
            ui->countLabel->setText(QString::number(rowNums));
        } else {
            qDebug() << "查询失败：" << query.lastError().text();
        }
    }
}

