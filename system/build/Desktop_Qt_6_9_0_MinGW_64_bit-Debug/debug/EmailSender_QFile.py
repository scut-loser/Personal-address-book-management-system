# EmailSender.py
import sys
import argparse
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.header import Header
from email.utils import formataddr


def send_email(to_email, content):
    # SMTP配置
    smtp_server = 'smtp.qq.com'
    smtp_port = 587
    smtp_user = '3286235592@qq.com'
    smtp_pass = 'rxhotxqhwaysdaic'

    # 创建邮件容器
    msg = MIMEMultipart()

    # 关键修复：使用 formataddr 正确编码邮件头
    msg['From'] = formataddr((
        Header('发件人名称', 'utf-8').encode(),  # 发件人名称（支持中文）
        smtp_user
    ))
    msg['To'] = formataddr((
        Header('收件人名称', 'utf-8').encode(),  # 收件人名称（支持中文）
        to_email
    ))
    msg['Subject'] = Header('动态生成文件测试', 'utf-8')

    # 添加正文
    msg.attach(MIMEText('这是一封生日祝福的电子邮件。', 'plain', 'utf-8'))

    # 添加内存文件为附件
    attachment = MIMEText(content, 'plain', 'utf-8')
    attachment.add_header(
        'Content-Disposition',
        'attachment',
        filename=Header('Happy_Birthday.txt', 'utf-8').encode()
    )
    msg.attach(attachment)

    # 发送邮件
    try:
        server = smtplib.SMTP(smtp_server, smtp_port)
        server.starttls()
        server.login(smtp_user, smtp_pass)
        server.sendmail(smtp_user, [to_email], msg.as_string())
        print("success")
    except Exception as e:
        print(f"Error: {str(e)}")
    finally:
        server.quit()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--to', required=True)
    parser.add_argument('--content', required=True)
    args = parser.parse_args()
    send_email(args.to, args.content)