#include "studentinformation.h"
#include "ui_studentinformation.h"
#include<QTableWidgetItem>
#include"mainwindow.h"
#include<QDebug>
#include"find_information.h"
#include"delete_information.h"
#include<QPainter>

StudentInformation::StudentInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInformation) {
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(7);
    QStringList header;
    header << "学号" << "姓名" << "性别" << "语文" << "数学" << "英语" << "总分";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    welcome(TeacherId);
    show_information(&S);
}

StudentInformation::~StudentInformation() {
    delete ui;
}

void StudentInformation::welcome(QString id) {
    ui->label->setText("欢迎教师用户:" + id + " 登录!");
    QFont font("Courier", 20);
    ui->label->setFont(font);
}

void StudentInformation::on_pushButton_clicked() {
    this->close();
}

void StudentInformation::on_pushButton_4_clicked() {
    Add_Information *addInformation = new Add_Information;
    addInformation->show();
    this->close();
}

void StudentInformation::show_information(StudentList *S) {
    int b = 0;//b用来记录结点的个数（头节点除外）
    StudentList *q = S->next;//使用指针p进行遍历，将指针p指向首元结点的地址
    while (q != nullptr)//当p不为空就遍历
    {
        q = q->next;//将p指向下一结点的地址，继续循环
        b++;//记录结点的个数
    }
    int flag = 1;//flag用来标记某一趟排序是否发生交换
    for (int i = 0; (i < b - 1) && (flag == 1); i++)//对链表进行冒泡排序
    {
        flag = 0;//flag置为0，如果本趟没有发生交换，则不会进行下一次排序
        StudentList *q = S->next;//将指针p指向首元结点
        for (int j = 0; j < b - i - 1; j++)//开始一趟排序
        {
            if (q->TotalScore < q->next->TotalScore)//对相邻的数进行比较
            {
                
                QString temp = QString::number(q->TotalScore);//相邻的数进行交换
                q->TotalScore = q->next->TotalScore;
                q->next->TotalScore = temp.toInt();
                temp = q->Id;//相邻的数进行交换
                q->Id = q->next->Id;
                q->next->Id = temp;
                QString Temp = q->Name;//相邻的数进行交换
                q->Name = q->next->Name;
                q->next->Name = Temp;
                Temp = q->Sex;//相邻的数进行交换
                q->Sex = q->next->Sex;
                q->next->Sex = Temp;
                QString temp1 = q->English;//相邻的数进行交换
                q->English = q->next->English;
                q->next->English = temp1;
                temp1 = q->Math;//相邻的数进行交换
                q->Math = q->next->Math;
                q->next->Math = temp1;
                temp1 = q->Chinese;//相邻的数进行交换
                q->Chinese = q->next->Chinese;
                q->next->Chinese = temp1;
                flag = 1;//因为本趟发生了交换，将flag置为1；
                
            }
            q = q->next;//将p指向下一结点，继续交换
        }
    }
    StudentList *p = S->next;
    while (p != nullptr) {
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
        p = p->next;
        
    }
    
}

void StudentInformation::on_pushButton_3_clicked() {
    Find_Information *F = new Find_Information;
    this->close();
    F->show();
}

void StudentInformation::on_pushButton_5_clicked() {
    Delete_Information *d = new Delete_Information;
    d->show();
    this->close();
}

void StudentInformation::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
