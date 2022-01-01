#include "linklist.h"
#include"QDebug"
#include"mainwindow.h"

LinkList::LinkList() {

}

void LinkList::InitLinkList(LinkList *L) {
    L = new LinkList;
    L->next = NULL;
    
}
