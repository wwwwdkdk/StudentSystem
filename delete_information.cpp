#include "delete_information.h"
#include "ui_delete_information.h"
#include<QMessageBox>
#include"studentinformation.h"
#include<QPainter>

Delete_Information::Delete_Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Delete_Information) {
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(7);
    QStringList header;
    header << "学号" << "姓名" << "性别" << "语文" << "数学" << "英语" << "总分";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

Delete_Information::~Delete_Information() {
    delete ui;
}

void Delete_Information::on_pushButton_clicked() {
    findStudent(&S);
}

void Delete_Information::findStudent(StudentList *S) {
    StudentList *p = S->next;
    while (p != nullptr) {
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
    QMessageBox::warning(this, "", "找不到您要删除的学生的学号!");
}

void Delete_Information::on_pushButton_3_clicked() {
    if (ui->tableWidget->item(0, 0) == 0) {
        QMessageBox::warning(this, "", "请先查找您要删除的学生");
    } else {
        
        deleteStudent(&S);
        StudentInformation *st = new StudentInformation;
        st->show();
        this->close();
    }
}

void Delete_Information::deleteStudent(StudentList *S) {
    StudentList *p = S;//使用指针p进行遍历查找
    StudentList *s = new StudentList;//创建一个新结点保存要删除的结点，以便释放内存
    while (p->next != nullptr)//当指针不为空就开始循环
    {
        if (p->next->Id == Id)//找到要删除的结点的前驱结点
        {
            s = p->next;//保存要删除的结点，以便释放内存
            p->next = s->next;//前驱结点的指针保存后驱结点的地址
            delete s;//释放内存
            QMessageBox::information(this, "", "删除成功");
            return;
        }
        p = p->next;//指向下一结点的地址，继续循环
    }
}

void Delete_Information::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}

void Delete_Information::on_pushButton_2_clicked() {
    this->close();
    StudentInformation *studentInformation = new StudentInformation;
    studentInformation->show();
}
