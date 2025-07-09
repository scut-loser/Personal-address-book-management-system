#ifndef LOGIN_VERIFICATION_H
#define LOGIN_VERIFICATION_H

#include <QWidget>
#include <mainwindow.h>
#include <QTimer>
#include <QCryptographicHash>
#include <QDateTime>
#include <QRandomGenerator>
#include <QDataStream>

namespace Ui {
class Login_Verification;
}

class Login_Verification : public QWidget
{
    Q_OBJECT

public:
    explicit Login_Verification(QWidget *parent = nullptr);
    ~Login_Verification();

    int sendEmail(const QString &toEmail, const QString &content);
    QString generateHighSecurityCaptcha(int codeLength);

private slots:
    void on_sendButton_clicked();
    void updateButtonState(); // 更新按钮状态槽函数

    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Login_Verification *ui;
    QString login_password;
    QTimer* m_timer;      // 定时器对象
    int m_remainingTime;  // 剩余时间
};

#endif // LOGIN_VERIFICATION_H
