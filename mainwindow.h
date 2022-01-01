#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"register.h"
#include"linklist.h"
#include"studentlist.h"

QT_BEGIN_NAMESPACE
extern class LinkList L;

extern class StudentList S;

extern QString TeacherId;
extern QString StudentId;
extern QString Id;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Register();
    void paintEvent(QPaintEvent *);

private:
    
    void Student_Login();
    void Teacher_Login();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
