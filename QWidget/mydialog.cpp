#include "mydialog.h"
#include "ui_mydialog.h"
#include<QMessageBox>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_acceptBtn_clicked()
{
    this->accept();//返回1
    QMessageBox::information(this,"西红柿","西红柿真好吃(*^▽^*)!!!");
}


void MyDialog::on_rejectBtn_clicked()
{
    this->reject();//返回0
    QMessageBox::information(this,"黄瓜","黄瓜真好吃(*^▽^*)!!!");
}


void MyDialog::on_donBtn_clicked()
{
    this->done(10000);//参数就是exec函数的返回值 相当于点击当前按钮然后返回的值
    QMessageBox::information(this,"茄子","茄子真好吃(*^▽^*)!!!");
}

