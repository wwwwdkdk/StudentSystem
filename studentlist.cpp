#include "studentlist.h"

StudentList::StudentList() {

}

void StudentList::InitStudentList(StudentList *S) {
    S = new StudentList;
    S->next = NULL;
}
