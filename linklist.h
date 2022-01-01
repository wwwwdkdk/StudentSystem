#ifndef LINKLIST_H
#define LINKLIST_H

#include<QString>

class LinkList {
public:
    LinkList();
    QString Id;
    QString Password;
    bool IsTeacher;
    LinkList *next;
    void InitLinkList(LinkList *L);
};

#endif // LINKLIST_H
