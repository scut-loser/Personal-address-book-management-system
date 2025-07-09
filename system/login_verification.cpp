#include "login_verification.h"
#include "ui_login_verification.h"

Login_Verification::Login_Verification(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login_Verification)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Login_Verification::updateButtonState);
    m_remainingTime = 0;

}

Login_Verification::~Login_Verification()
{
    delete ui;
}

void Login_Verification::on_sendButton_clicked()
{
    // 生成并发送验证码
    login_password = generateHighSecurityCaptcha(10);
    int flag = sendEmail("3286235592@qq.com", login_password);

    if(flag == 0)
    {
        // 禁用按钮并启动冷却
        ui->sendButton->setEnabled(false);
        m_remainingTime = 60; // 设置冷却时间60秒
        m_timer->start(1000); // 每秒触发一次
        updateButtonState();   // 立即更新按钮状态
        QMessageBox::information(this, "提示", "验证码已发送，请注意查收。");
    }
    else
    {
        QMessageBox::warning(this, "警告", "验证码发送失败，请稍后再试！");
        return;
    }

    // 禁用按钮并启动冷却
    // ui->sendButton->setEnabled(false);
    // m_remainingTime = 60; // 设置冷却时间60秒
    // m_timer->start(1000); // 每秒触发一次
    // updateButtonState();   // 立即更新按钮状态
}

// 更新状态
void Login_Verification::updateButtonState()
{
    m_remainingTime--;

    if (m_remainingTime <= 0) {
        m_timer->stop();
        ui->sendButton->setEnabled(true);
        ui->sendButton->setText("发送");
    } else {
        ui->sendButton->setText(QString("%1s").arg(m_remainingTime));
    }
}

// 发送验证码至邮箱
int Login_Verification::sendEmail(const QString &toEmail, const QString &content) {
    QProcess process;
    QString scriptPath = QCoreApplication::applicationDirPath() + "/EmailSender_text.py";
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

// 生成验证码
QString Login_Verification::generateHighSecurityCaptcha(int codeLength) {
    // 生成复合随机种子（时间戳+系统级随机数）
    quint64 timestamp = QDateTime::currentMSecsSinceEpoch();
    quint64 secureRandom = QRandomGenerator::system()->generate64();

    // 将种子序列化为字节数组
    QByteArray seedBytes;
    QDataStream seedStream(&seedBytes, QIODevice::WriteOnly);
    seedStream << timestamp << secureRandom;

    // 进行1000次SHA3-256迭代哈希（抗暴力破解）
    QByteArray hashResult = QCryptographicHash::hash(seedBytes, QCryptographicHash::Sha3_256);
    for (int i = 0; i < 1000; ++i) {
        hashResult = QCryptographicHash::hash(hashResult, QCryptographicHash::Sha3_256);
    }

    // 使用抗偏置抽样算法生成验证码
    const QString charSet = "ABCDEFGHJKLMNPQRSTUVWXYZ23456789"; // 排除易混淆字符
    QString captcha;
    int samplingOffset = 0;

    while (captcha.length() < codeLength) {
        // 使用哈希值的不同部分进行采样
        quint16 twoBytes = *reinterpret_cast<const quint16*>(
            hashResult.constData() + (samplingOffset % (hashResult.size() - 1))
            );

        // 采用拒绝采样法消除模偏差
        if (twoBytes < 0xFFF0) {  // 保留0.006%的拒绝概率
            captcha.append(charSet.at(twoBytes % charSet.size()));
            samplingOffset += 2;
        }
        samplingOffset++;
    }

    return captcha;
}

void Login_Verification::on_confirmButton_clicked()
{
    if(ui->lineEdit->text() == login_password)
    {
        MainWindow *w = new MainWindow;
        w->setAttribute(Qt::WA_DeleteOnClose);
        w->show();
        this->close();
    }

    else
    {
        QMessageBox::warning(this, "警告", "验证码错误！！！");
        ui->lineEdit->clear();
    }
}


void Login_Verification::on_cancelButton_clicked()
{
    this->close();
}

