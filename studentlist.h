#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include<QString>

class StudentList {
public:
    StudentList();
    QString Name;
    QString Id;
    QString Sex;
    QString Chinese;
    QString English;
    QString Math;
    int TotalScore;
    StudentList *next;
    void InitStudentList(StudentList *S);
    
};

#endif // STUDENTLIST_H
