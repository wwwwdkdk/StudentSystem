#include "student_login.h"
#include "ui_student_login.h"
#include"mainwindow.h"
#include<QMessageBox>
#include"rankinglist.h"
#include"studentinformation.h"
#include"QDebug"
#include<QPainter>

Student_Login::Student_Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student_Login) {
    ui->setupUi(this);
    connect(ui->btn_back, &QPushButton::clicked, this, &QWidget::close);
}

Student_Login::~Student_Login() {
    delete ui;
}

void Student_Login::on_btn_Ok_clicked() {
    if (ui->text_line->text() == nullptr) {
        QMessageBox::warning(this, "", "您的用户名为空！");
    } else if (ui->password_line_2->text() == nullptr) {
        QMessageBox::warning(this, "", "您的密码为空！");
    } else {
        LinkList *p = &L;
        if (p->next == nullptr) {
            QMessageBox::warning(this, "", "找不到用户名！");
        }
        while (p->next != nullptr) {
            if (p->next->Id == ui->text_line->text()) {
                if ((p->next->Password == ui->password_line_2->text()) && !p->next->IsTeacher) {
                    if (QMessageBox::Ok ==
                        QMessageBox::information(this, "", "登录成功", QMessageBox::Ok, QMessageBox::Cancel)) {
                        RankingList *R = new RankingList;
                        R->show();
                        this->close();
                        return;
                    } else {
                        RankingList *R = new RankingList;
                        R->show();
                        this->close();
                        return;
                    }
                } else if ((p->next->Password == ui->password_line_2->text()) && p->next->IsTeacher) {
                    if (QMessageBox::Ok ==
                        QMessageBox::information(this, "", "登录成功", QMessageBox::Ok, QMessageBox::Cancel)) {
                        StudentInformation *R = new StudentInformation;
                        TeacherId = p->next->Id;
                        R->show();
                        this->close();
                        R->welcome(TeacherId);
                        return;
                    } else {
                        StudentInformation *R = new StudentInformation;
                        R->show();
                        this->close();
                        return;
                    }
                } else {
                    QMessageBox::warning(this, "", "您的密码有误！");
                    return;
                }
            }
            p = p->next;
            if (p->next == nullptr) {
                QMessageBox::warning(this, "", "找不到用户名！");
                return;
            }
        }
    }
}

void Student_Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
