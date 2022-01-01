#include "find_information.h"
#include "ui_find_information.h"
#include"studentinformation.h"
#include"mainwindow.h"
#include"QMessageBox"
#include"update_information.h"
#include"QPainter"

Find_Information::Find_Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Find_Information) {
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(7);
    QStringList header;
    header << "学号" << "姓名" << "性别" << "语文" << "数学" << "英语" << "总分";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

Find_Information::~Find_Information() {
    delete ui;
}

void Find_Information::on_pushButton_2_clicked() {
    this->close();
    StudentInformation *S = new StudentInformation;
    S->show();
}

void Find_Information::on_pushButton_clicked() {
    FindId(&S);
}

void Find_Information::FindId(StudentList *S) {
    StudentList *p = S->next;
    while (p != NULL) {
        if (p->Id == ui->line_id->text()) {
            int rowcount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowcount);
            ui->tableWidget->setItem(rowcount, 0, new QTableWidgetItem(p->Id));
            ui->tableWidget->item(rowcount, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 1, new QTableWidgetItem(p->Name));
            ui->tableWidget->item(rowcount, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 2, new QTableWidgetItem(p->Sex));
            ui->tableWidget->item(rowcount, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 3, new QTableWidgetItem(p->Chinese));
            ui->tableWidget->item(rowcount, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 4, new QTableWidgetItem(p->English));
            ui->tableWidget->item(rowcount, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 5, new QTableWidgetItem(p->Math));
            ui->tableWidget->item(rowcount, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(rowcount, 6, new QTableWidgetItem(QString::number(p->TotalScore)));
            ui->tableWidget->item(rowcount, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            Id = p->Id;
            return;
        }
        p = p->next;
    }
    QMessageBox::warning(this, "", "找不到您要修改的学生的学号!");
}

void Find_Information::on_pushButton_3_clicked() {
    if (ui->tableWidget->item(0, 0) == 0) {
        QMessageBox::warning(this, "", "请先查找您要修改的学生");
    } else {
        Update_Information *U = new Update_Information;
        U->show();
        this->close();
    }
}

void Find_Information::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
