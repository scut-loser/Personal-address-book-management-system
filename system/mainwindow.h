#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <listitemdelegate.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QListWidget>
#include <QTableView>
#include <QKeyEvent>
#include <QClipboard>
#include <QCoreApplication>
#include <QInputDialog>
#include <QProcessEnvironment>
#include "centeraligndelegate.h"
#include "adddata.h"
#include "amenddata.h"
#include "deletedata.h"
#include "birthinspecifiedmonth.h"
#include "birthcongratulation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupDatabase(); //初始化数据库连接
    void refreshTable(const QString &sql); // 刷新TableView数据
    void adjustTableColumns(QTableView* tableView); // 列宽调整

private slots:
    void on_searchButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void namesortSActionslot();
    void namesortJActionslot();
    void birthsortSActionslot();
    void birthsortJActionslot();
    void addActionslot();
    void amendActionslot();
    void deleteActionslot();
    void birthInMonthslot();
    void birthRemindingslot();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db; // 数据库
    QSqlQueryModel* model; // 查询模型
    QString tableName, fieldName, typeName;
    QSortFilterProxyModel *proxymodel;
};
#endif // MAINWINDOW_H
