#ifndef FIND_INFORMATION_H
#define FIND_INFORMATION_H

#include <QWidget>
#include"studentlist.h"

namespace Ui {
    class Find_Information;
}
class Find_Information : public QWidget {
Q_OBJECT

public:
    explicit Find_Information(QWidget *parent = nullptr);
    ~Find_Information();
    void FindId(StudentList *S);
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Find_Information *ui;
};

#endif // FIND_INFORMATION_H
