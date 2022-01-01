#include "rankinglist.h"
#include "ui_rankinglist.h"
#include<QPainter>

RankingList::RankingList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankingList) {
    ui->setupUi(this);
    ui->label->setText("学生成绩排名");
    QFont font("Courier", 20);
    ui->label->setFont(font);
    ui->qtablewidget->setColumnCount(7);
    QStringList header;  //QString类型的List容器
    header << "学号" << "姓名" << "性别" << "语文" << "数学" << "英语" << "总分";
    ui->qtablewidget->setHorizontalHeaderLabels(header);//设置表头内容
    ui->qtablewidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->qtablewidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->qtablewidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    showInformation(&S);
}

RankingList::~RankingList() {
    delete ui;
}

void RankingList::showInformation(StudentList *L) {
    int b = 0;//b用来记录结点的个数（头节点除外）
    StudentList *p = L->next;//使用指针p进行遍历，将指针p指向首元结点的地址
    while (p != nullptr)//当p不为空就遍历
    {
        p = p->next;//将p指向下一结点的地址，继续循环
        b++;//记录结点的个数
    }
    int flag = 1;//flag用来标记某一趟排序是否发生交换
    for (int i = 0; (i < b - 1) && (flag == 1); i++)//对链表进行冒泡排序
    {
        flag = 0;//flag置为0，如果本趟没有发生交换，则不会进行下一次排序
        StudentList *p = L->next;//将指针p指向首元结点
        for (int j = 0; j < b - i - 1; j++)//开始一趟排序
        {
            if (p->TotalScore < p->next->TotalScore)//对相邻的数进行比较
            {
                
                QString temp = QString::number(p->TotalScore);//相邻的数进行交换
                p->TotalScore = p->next->TotalScore;
                p->next->TotalScore = temp.toInt();
                temp = p->Id;//相邻的数进行交换
                p->Id = p->next->Id;
                p->next->Id = temp;
                QString Temp = p->Name;//相邻的数进行交换
                p->Name = p->next->Name;
                p->next->Name = Temp;
                Temp = p->Sex;//相邻的数进行交换
                p->Sex = p->next->Sex;
                p->next->Sex = Temp;
                QString temp1 = p->English;//相邻的数进行交换
                p->English = p->next->English;
                p->next->English = temp1;
                temp1 = p->Math;//相邻的数进行交换
                p->Math = p->next->Math;
                p->next->Math = temp1;
                temp1 = p->Chinese;//相邻的数进行交换
                p->Chinese = p->next->Chinese;
                p->next->Chinese = temp1;
                flag = 1;//因为本趟发生了交换，将flag置为1；
                
            }
            p = p->next;//将p指向下一结点，继续交换
        }
    }
    StudentList *q = L->next;
    while (q != nullptr) {
        int rowcount = ui->qtablewidget->rowCount();
        ui->qtablewidget->insertRow(rowcount);
        ui->qtablewidget->setItem(rowcount, 0, new QTableWidgetItem(q->Id));
        ui->qtablewidget->item(rowcount, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 1, new QTableWidgetItem(q->Name));
        ui->qtablewidget->item(rowcount, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 2, new QTableWidgetItem(q->Sex));
        ui->qtablewidget->item(rowcount, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 3, new QTableWidgetItem(q->Chinese));
        ui->qtablewidget->item(rowcount, 3)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 4, new QTableWidgetItem(q->English));
        ui->qtablewidget->item(rowcount, 4)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 5, new QTableWidgetItem(q->Math));
        ui->qtablewidget->item(rowcount, 5)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->qtablewidget->setItem(rowcount, 6, new QTableWidgetItem(QString::number(q->TotalScore)));
        ui->qtablewidget->item(rowcount, 6)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        q = q->next;
    }
}

void RankingList::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
}
