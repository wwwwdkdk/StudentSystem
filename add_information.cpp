#include "add_information.h"
#include "ui_add_information.h"
#include"studentinformation.h"
#include<QMessageBox>
#include"mainwindow.h"
#include<QPainter>

Add_Information::Add_Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_Information) {
    ui->setupUi(this);
    ui->label_information->setText("请在下方输入您要添加的学生信息");
    QFont font("Courier", 20);
    ui->label_information->setFont(font);
}

Add_Information::~Add_Information() {
    delete ui;
}

void Add_Information::on_pushButton_2_clicked() {
    this->close();
    StudentInformation *S = new StudentInformation;
    S->show();
}

void Add_Information::on_Btn_Ok_clicked() {
    AddInformation(&S);
}

void Add_Information::AddInformation(StudentList *S) {
    QString Id = ui->line_id->text();
    QString Name = ui->line_name->text();
    bool IsMan = ui->rad_man->isChecked();
    bool IsWoman = ui->rad_woman->isChecked();
    QString Chinese = ui->line_chinese->text();
    QString English = ui->line_english->text();
    QString Math = ui->line_math->text();
    if (Id == nullptr) {
        QMessageBox::warning(this, "", "学号为空!");
    } else if (Name == nullptr) {
        QMessageBox::warning(this, "", "姓名为空!");
    } else if (!IsMan && !IsWoman) {
        QMessageBox::warning(this, "", "性别为空!");
    } else if (Chinese == nullptr) {
        QMessageBox::warning(this, "", "语文成绩为空!");
    } else if (English == nullptr) {
        QMessageBox::warning(this, "", "英语成绩为空!");
    } else if (Math == nullptr) {
        QMessageBox::warning(this, "", "数学成绩为空!");
    } else {
        StudentList *p = new StudentList;
        StudentList *q = S->next;
        while (q != nullptr) {
            if (q->Id == Id) {
                QMessageBox::warning(this, "", "存在当前学号");
                return;
            }
            q = q->next;
        }
        p->Id = Id;
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
        p->next = S->next;
        S->next = p;
        if (QMessageBox::Ok == QMessageBox::information(this, "", "添加成功", QMessageBox::Ok, QMessageBox::Cancel)) {
            this->close();
            StudentInformation *S = new StudentInformation;
            S->show();
        } else {
            this->close();
            StudentInformation *S = new StudentInformation;
            S->show();
        }
    }
}

void Add_Information::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
