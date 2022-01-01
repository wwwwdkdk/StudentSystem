#include "register.h"
#include "ui_register.h"
#include"mainwindow.h"
#include<QDialog>
#include<QMessageBox>
#include"QDebug"
#include<QPainter>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register) {
    ui->setupUi(this);
}

Register::~Register() {
    delete ui;
}

void Register::on_btn_Ok_clicked() {
    AddUser(&L);
}

void Register::InitRegister(Register *R) {
    R = new Register;
    R->next = nullptr;
    qDebug() << "初始化成功";
}

void Register::on_btn_back_clicked() {
    this->close();
}

void Register::AddUser(LinkList *R) {
    QString id = ui->line_id->text();
    QString password = ui->line_password->text();
    QString password2 = ui->line_password2->text();
    
    if (id == nullptr) {
        QMessageBox::warning(this, " ", "您的用户名为空！");
    } else if (id.length() < 6) {
        QMessageBox::warning(this, " ", "您的用户名小于六位！");
    } else if (password == nullptr) {
        QMessageBox::warning(this, " ", "您的密码为空！");
    } else if (password.length() < 6) {
        QMessageBox::warning(this, " ", "您的密码小于六位！");
    } else if (password != password2) {
        QMessageBox::warning(this, " ", "两次密码不一致！");
    } else {
        LinkList *P = R;
        while (P->next != nullptr) {
            if (P->next->Id == id) {
                QMessageBox::warning(this, " ", "存在当前用户名");
                return;
            }
            P = P->next;
        }
        if (!ui->Btn_Student->isChecked() && !ui->Btn_Teacher->isChecked()) {
            QMessageBox::warning(this, " ", "请选择您的用户类型");
        } else if (ui->Btn_Student->isChecked()) {
            LinkList *L = new LinkList;
            L->Id = id;
            L->Password = password;
            L->IsTeacher = false;
            L->next = R->next;
            R->next = L;
            if (QMessageBox::Ok ==
                QMessageBox::information(this, " ", "学生用户注册成功", QMessageBox::Ok | QMessageBox::Cancel)) {
                Register::close();
            } else {
                Register::close();
            }
        } else if (ui->Btn_Teacher->isChecked()) {
            LinkList *L = new LinkList;
            L->Id = id;
            L->Password = password;
            L->IsTeacher = true;
            L->next = R->next;
            R->next = L;
            if (QMessageBox::Ok == QMessageBox::information(this, " ", "教师用户注册成功", QMessageBox::Ok | QMessageBox::Cancel)) {
                Register::close();
            } else {
                Register::close();
            }
        }
    }
}

void Register::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
