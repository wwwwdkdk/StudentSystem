#include "update_information.h"
#include "ui_update_information.h"
#include"mainwindow.h"
#include"studentlist.h"
#include"QMessageBox"
#include"studentinformation.h"
#include<QPainter>

Update_Information::Update_Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update_Information) {
    ui->setupUi(this);
    InitLineEdit(&S);
    
}

Update_Information::~Update_Information() {
    delete ui;
}

void Update_Information::InitLineEdit(StudentList *S) {
    StudentList *p = S;
    while (p->next != nullptr) {
        if (p->next->Id == Id) {
            ui->line_id->setText(Id);
            ui->line_name->setText(p->next->Name);
            if (p->next->Sex == "男") {
                ui->rad_man->setChecked(true);
            } else {
                ui->rad_woman->setChecked(true);
            }
            ui->line_chinese->setText(p->next->Chinese);
            ui->line_english->setText(p->next->English);
            ui->line_math->setText(p->next->Math);
        }
        p = p->next;
    }
}

void Update_Information::on_Btn_Ok_clicked() {
    update(&S);
}

void Update_Information::update(StudentList *S) {
    Update_Information *U = new Update_Information;
    QString id = ui->line_id->text();
    QString Name = ui->line_name->text();
    bool IsMan = ui->rad_man->isChecked();
    bool IsWoman = ui->rad_woman->isChecked();
    QString Chinese = ui->line_chinese->text();
    QString English = ui->line_english->text();
    QString Math = ui->line_math->text();
    if (id == nullptr) {
        QMessageBox::warning(this, "", "学号为空!");
        U->show();
        this->close();
    } else if (Name == nullptr) {
        QMessageBox::warning(this, "", "姓名为空!");
        U->show();
        this->close();
    } else if (!IsMan && !IsWoman) {
        QMessageBox::warning(this, "", "性别为空!");
        U->show();
        this->close();
    } else if (Chinese == nullptr) {
        QMessageBox::warning(this, "", "语文成绩为空!");
        U->show();
        this->close();
    } else if (English == nullptr) {
        QMessageBox::warning(this, "", "英语成绩为空!");
        U->show();
        this->close();
    } else if (Math == nullptr) {
        QMessageBox::warning(this, "", "数学成绩为空!");
        U->show();
        this->close();
    } else {
        StudentList *q = S->next;
        while (q != nullptr) {
            if ((q->Id == id) && (q->Id != Id)) {
                QMessageBox::warning(this, "", "存在当前学号");
                U->show();
                this->close();
                return;
            }
            q = q->next;
        }
        StudentList *p = S->next;
        while (p != nullptr) {
            if (p->Id == Id) {
                p->Id = id;
                p->Name = Name;
                if (IsMan) {
                    p->Sex = "男";
                }
                if (IsWoman) {
                    p->Sex = "女";
                }
                int tmp = Chinese.toInt() + English.toInt() + Math.toInt();
                p->Chinese = Chinese;
                p->English = English;
                p->Math = Math;
                p->TotalScore = tmp;
                if (QMessageBox::Ok ==
                    QMessageBox::information(this, "", "修改成功", QMessageBox::Ok, QMessageBox::Cancel)) {
                    this->close();
                    StudentInformation *S = new StudentInformation;
                    S->show();
                } else {
                    this->close();
                    StudentInformation *S = new StudentInformation;
                    S->show();
                }
                return;
            }
        }
        p = p->next;
    }
}

void Update_Information::on_pushButton_2_clicked() {
    this->close();
    StudentInformation *S = new StudentInformation;
    S->show();
}

void Update_Information::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
