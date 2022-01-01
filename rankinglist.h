#ifndef RANKINGLIST_H
#define RANKINGLIST_H

#include <QWidget>
#include"studentlist.h"
#include"mainwindow.h"

namespace Ui {
    class RankingList;
}
class RankingList : public QWidget {
Q_OBJECT

public:
    explicit RankingList(QWidget *parent = nullptr);
    ~RankingList();
    void showInformation(StudentList *L);
    void paintEvent(QPaintEvent *);

private:
    Ui::RankingList *ui;
};

#endif // RANKINGLIST_H
