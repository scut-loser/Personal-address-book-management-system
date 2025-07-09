#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QStyledItemDelegate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->setItemDelegate(new ListItemDelegate(ui->listWidget)); // 为QListWidget选项之间绘制浅色线条边界

    // 初始化数据库连接
    setupDatabase();

    // 连接失败弹窗提示
    if(!(db.open()))
    {
        QMessageBox::warning(this, "警告", "连接失败");
    }

    // 绑定查询模型到tableview上，执行查询时将结果呈现在tableview上
    model = new QSqlQueryModel(this);
    ui->tableView->setModel(model);

    // 使数据居中对齐
    ui->tableView->setItemDelegate(new CenterAlignDelegate(ui->tableView));

    // 初始化代理模型
    proxymodel = new QSortFilterProxyModel(this);
    proxymodel->setSourceModel(model);


    // 默认打开后呈现“全部”界面
    tableName = "contacts";
    refreshTable("SELECT name AS 姓名, birthdate AS 出生日期, phone AS 电话, email AS 邮箱 FROM contacts");

    // 姓名查询关联Enter键
    connect(ui->searchLineEdit, &QLineEdit::returnPressed, this, &MainWindow::on_searchButton_clicked);

    // 实现排序功能
    connect(ui->namesortSAction, &QAction::triggered, this, &MainWindow::namesortSActionslot);
    connect(ui->namesortJAction, &QAction::triggered, this, &MainWindow::namesortJActionslot);
    connect(ui->birthsortSAction, &QAction::triggered, this, &MainWindow::birthsortSActionslot);
    connect(ui->birthsortJAction, &QAction::triggered, this, &MainWindow::birthsortJActionslot);

    // 增改删
    connect(ui->addAction, &QAction::triggered, this, &MainWindow::addActionslot);
    connect(ui->amendAction, &QAction::triggered, this, &MainWindow::amendActionslot);
    connect(ui->deleteAction, &QAction::triggered, this, &MainWindow::deleteActionslot);

    // 统计在指定月份出生的人数
    connect(ui->birthInMonth, &QAction::triggered, this, &MainWindow::birthInMonthslot);

    // 近期生日
    connect(ui->birthReminding, &QAction::triggered, this, &MainWindow::birthRemindingslot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 初始化数据库
void MainWindow::setupDatabase()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("address");
    db.setHostName("localhost");
    db.setUserName("remote_user");
    QString password = QProcessEnvironment::systemEnvironment().value("DB_REMOTE_PASSWORD");
    db.setPassword(password);
}

// 列宽调整
void MainWindow::adjustTableColumns(QTableView* tableView) {
    if (!tableView || !tableView->model()) return;

    QHeaderView* header = tableView->horizontalHeader();
    int viewWidth = tableView->viewport()->width(); // 排除滚动条后的有效宽度
    int columnCount = tableView->model()->columnCount();

    if (columnCount == 0) return;

    // 计算每列宽度并分配余数
    int baseWidth = viewWidth / columnCount;
    int remainder = viewWidth % columnCount;

    // 禁止用户手动调整列宽
    // header->setSectionResizeMode(QHeaderView::Fixed);

    for (int col = 0; col < columnCount; ++col) {
        int width = baseWidth + (col < remainder ? 1 : 0);
        tableView->setColumnWidth(col, width);
    }
}

// 执行查询语句后刷新TableView数据
void MainWindow::refreshTable(const QString &sql) {

    // 执行SQL查询
    ui->tableView->setModel(model);
    model->setQuery(sql);
    if (model->lastError().isValid()) {
        qDebug() << "查询错误：" << model->lastError().text();
    }

    // 调整列宽
    adjustTableColumns(ui->tableView);
}

// 按姓名查询
void MainWindow::on_searchButton_clicked()
{
    QString searchText = ui->searchLineEdit->text();
    QSqlQuery query;

    if(tableName == "contacts")
    {
        QString sql = "SELECT name AS 姓名, birthdate AS 出生日期, phone AS 电话, email AS 邮箱 FROM contacts WHERE name LIKE ?";
        query.prepare(sql);
        query.addBindValue("%" + searchText + "%");

        if (query.exec()) {
            // 将结果展示到 TableView
            model->setQuery(std::move(query));
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
                          "WHERE c.type = '%4' AND name LIKE ?"
                          ).arg(fieldName).arg(tableName).arg(tableName).arg(typeName);

        query.prepare(sql);
        query.addBindValue("%" + searchText +"%");

        if (query.exec()) {
            // 将结果展示到 TableView
            model->setQuery(std::move(query));
        } else {
            qDebug() << "查询失败：" << query.lastError().text();
        }
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString type = item->text();

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

    // 执行查询
    refreshTable(sql);
}

// 实现排序
void MainWindow::namesortSActionslot()
{
    proxymodel->sort(0);
    ui->tableView->setModel(proxymodel);
}

void MainWindow::namesortJActionslot()
{
    proxymodel->sort(0, Qt::DescendingOrder);
    ui->tableView->setModel(proxymodel);
}

void MainWindow::birthsortSActionslot()
{
    proxymodel->sort(1);
    ui->tableView->setModel(proxymodel);
}

void MainWindow::birthsortJActionslot()
{
    proxymodel->sort(1, Qt::DescendingOrder);
    ui->tableView->setModel(proxymodel);
}

// 增改删
void MainWindow::addActionslot()
{
    addData *add_D = new addData;
    add_D->setAttribute(Qt::WA_DeleteOnClose);
    add_D->show();
}

void MainWindow::amendActionslot()
{
    amendData *amend_D = new amendData;
    amend_D->setAttribute(Qt::WA_DeleteOnClose);
    amend_D->show();
}

void MainWindow::deleteActionslot()
{
    deleteData *delete_D = new deleteData;
    delete_D->setAttribute(Qt::WA_DeleteOnClose);
    delete_D->show();
}

// 统计在指定月份出生的人数
void MainWindow::birthInMonthslot()
{
    birthInSpecifiedMonth *b_I_S_M = new birthInSpecifiedMonth;
    b_I_S_M->setAttribute(Qt::WA_DeleteOnClose);
    b_I_S_M->show();
}

// 近期生日
void MainWindow::birthRemindingslot()
{
    birthCongratulation *birth_C = new birthCongratulation;
    birth_C->setAttribute(Qt::WA_DeleteOnClose);
    birth_C->show();
}
