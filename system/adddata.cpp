#include "adddata.h"
#include "ui_adddata.h"

addData::addData(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addData)
{
    ui->setupUi(this);
}

addData::~addData()
{
    delete ui;
}

void addData::on_confirmButton_clicked()
{
    QString type = ui->comboBox->currentText();

    addData_1 *add_D_1 = new addData_1(type);
    add_D_1->setAttribute(Qt::WA_DeleteOnClose);
    add_D_1->show();
    this->close();
}


void addData::on_cancelButton_clicked()
{
    this->close();
}

