#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"register.h"
#include"student_login.h"
#include"QDebug"
#include"linklist.h"
#include<QPainter>

LinkList L;
StudentList S;
QString TeacherId;
QString StudentId;
QString Id;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->btn_exit, &QPushButton::clicked, this, &QWidget::close);
    connect(ui->btn_register, &QPushButton::clicked, this, &MainWindow::Register);
    connect(ui->student_login, &QPushButton::clicked, this, &MainWindow::Student_Login);
    L.InitLinkList(&L);
    S.InitStudentList(&S);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Register() {
    class Register *r = new class Register;
    r->show();
}

void MainWindow::Student_Login() {
    class Student_Login *s = new class Student_Login;
    s->show();
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/IMG_1504.JPG"));
    painter.drawPixmap(100, 50, 600, 150, QPixmap(":/studentSystem.png"));
}
