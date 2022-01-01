#ifndef STUDENT_LOGIN_H
#define STUDENT_LOGIN_H

#include <QWidget>

namespace Ui {
    class Student_Login;
}
class Student_Login : public QWidget {
Q_OBJECT

public:
    explicit Student_Login(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Student_Login();

private slots:
    void on_btn_Ok_clicked();

private:
    Ui::Student_Login *ui;
    
};

#endif // STUDENT_LOGIN_H
