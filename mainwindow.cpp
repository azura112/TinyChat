#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dialog=new LoginDialog(this);
    this->setCentralWidget(_login_dialog);
    //_login_dialog->show();
    connect(_login_dialog,&LoginDialog::switchRegister,this,&MainWindow::SlotSwitchReg);
    _register_dialog =new Register_Dialog(this);

    _login_dialog->setWindowFlags(Qt::CustomizeWindowHint| Qt::FramelessWindowHint);
    _register_dialog->setWindowFlags(Qt::CustomizeWindowHint| Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    qDebug()<<"~MainWindow()\n";
    delete ui;
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_register_dialog);
    _login_dialog->hide();
    _register_dialog->show();
}
