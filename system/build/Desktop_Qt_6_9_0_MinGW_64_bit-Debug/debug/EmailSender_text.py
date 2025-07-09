# EmailSender.py
import sys
import argparse
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr


def send_email(to_email, content):
    smtp_server = 'smtp.qq.com'
    smtp_port = 587
    smtp_user = '3286235592@qq.com'
    smtp_pass = 'rxhotxqhwaysdaic'

    msg = MIMEMultipart()
    msg['From'] = formataddr((
        Header('发件人名称', 'utf-8').encode(),
        smtp_user
    ))
    msg['To'] = formataddr((
        Header('收件人名称', 'utf-8').encode(),
        to_email
    ))
    msg['Subject'] = Header('登录验证邮件', 'utf-8')

    # 添加正文
    content = "验证码：" + content
    msg.attach(MIMEText(content, 'plain', 'utf-8'))


    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(smtp_user, smtp_pass)

        # 关键修改：显式验证收件人地址
        server.verify(to_email)  # 可选步骤（非所有服务器支持）

        # 发送邮件并捕获收件人拒绝错误
        server.sendmail(smtp_user, [to_email], msg.as_string())
        print("success")
    except smtplib.SMTPRecipientsRefused as e:
        error_msg = f"收件人地址不存在或被拒绝：{to_email}\n错误详情：{e}"
        print(error_msg)
    except smtplib.SMTPResponseException as e:
        error_code = e.smtp_code
        error_msg = f"SMTP服务器返回错误（代码 {error_code}）：{e.smtp_error.decode()}"
        print(error_msg)
    except Exception as e:
        print(f"其他错误：{str(e)}")
    finally:
        if 'server' in locals():
            server.quit()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--to', required=True)
    parser.add_argument('--content', required=True)
    args = parser.parse_args()
    send_email(args.to, args.content)