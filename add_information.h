#ifndef ADD_INFORMATION_H
#define ADD_INFORMATION_H

#include <QWidget>
#include"studentlist.h"
namespace Ui {
class Add_Information;
}

class Add_Information : public QWidget
{
    Q_OBJECT

public:
    explicit Add_Information(QWidget *parent = nullptr);
    ~Add_Information();
    void AddInformation(StudentList *S);
     void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_2_clicked();

    void on_Btn_Ok_clicked();

private:
    Ui::Add_Information *ui;
};

#endif // ADD_INFORMATION_H
