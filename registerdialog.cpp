#include "registerdialog.h"
#include "ui_register_dialog.h"
#include "GLOBAL.h"
Register_Dialog::Register_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register_Dialog)
{
    ui->setupUi(this);
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    ui->password_lineEdit2->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
}

Register_Dialog::~Register_Dialog()
{
    qDebug()<<"~Register_Dialog()\n";
    delete ui;
}

void Register_Dialog::on_pushButton_2_clicked()
{
    auto email = ui->email_lineEdit->text();
    QRegularExpression regex(R"###(*@*\.com)###");
    if(regex.match(email).hasMatch()) {

    }else {
        showTip("邮箱地址格式错误",false);
    }
}

void Register_Dialog::showTip(const QString& msg, bool ok)
{
    ui->err_tip->setText(msg);
    if(ok)
        ui->err_tip->setProperty("state","normal");
    else ui->err_tip->setProperty("state","err");
    repolish(ui->err_tip);
}

