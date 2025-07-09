#ifndef ADDDATA_H
#define ADDDATA_H

#include <QWidget>
#include "adddata_1.h"

namespace Ui {
class addData;
}

class addData : public QWidget
{
    Q_OBJECT

public:
    explicit addData(QWidget *parent = nullptr);
    ~addData();

private slots:
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::addData *ui;
};

#endif // ADDDATA_H
