#ifndef UPDATE_INFORMATION_H
#define UPDATE_INFORMATION_H

#include <QWidget>
#include"studentlist.h"

namespace Ui {
    class Update_Information;
}
class Update_Information : public QWidget {
Q_OBJECT

public:
    explicit Update_Information(QWidget *parent = nullptr);
    ~Update_Information();
    void InitLineEdit(StudentList *S);
    void update(StudentList *S);
    void paintEvent(QPaintEvent *);

private slots:
    void on_Btn_Ok_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Update_Information *ui;
};

#endif // UPDATE_INFORMATION_H
