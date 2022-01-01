#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H

#include <QWidget>
#include"add_information.h"

namespace Ui {
    class StudentInformation;
}
class StudentInformation : public QWidget {
Q_OBJECT

public:
    explicit StudentInformation(QWidget *parent = nullptr);
    ~StudentInformation();
    void welcome(QString id);
    void show_information(StudentList *S);
    void paintEvent(QPaintEvent *);

private slots:
    
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();

private:
    Ui::StudentInformation *ui;
};

#endif // STUDENTINFORMATION_H
