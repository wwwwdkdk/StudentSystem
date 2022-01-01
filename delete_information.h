#ifndef DELETE_INFORMATION_H
#define DELETE_INFORMATION_H

#include <QWidget>
#include<mainwindow.h>
#include"studentlist.h"

namespace Ui {
    class Delete_Information;
}
class Delete_Information : public QWidget {
Q_OBJECT

public:
    explicit Delete_Information(QWidget *parent = nullptr);
    ~Delete_Information();
    void findStudent(StudentList *S);
    void deleteStudent(StudentList *S);
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Delete_Information *ui;
};

#endif // DELETE_INFORMATION_H
