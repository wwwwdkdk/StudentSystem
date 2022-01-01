#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include"linklist.h"

namespace Ui {
    class Register;
}
class Register : public QWidget {
Q_OBJECT

public:
    QString ID;
    QString Password;
    Register *next;
    void AddUser(LinkList *R);
    void InitRegister(Register *R);
    explicit Register(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    ~Register();

private slots:
    void on_btn_Ok_clicked();
    void on_btn_back_clicked();

private:
    Ui::Register *ui;
    
};

#endif // REGISTER_H
