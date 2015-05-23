#include "list.h"
#include "linkedList.h"
#include "doubleLinkedList.h"

int main()
{
    List *list = new LinkedList();
    list->add(5);
    list->add(6);
    list->add(7);
    list->remove(7);
    list->print();
    delete list;
    List *doubeList = new DoubleLinkedList();
    doubeList->add(5);
    doubeList->add(6);
    doubeList->add(7);
    doubeList->remove(7);
    doubeList->print();
    delete doubeList;
    return 0;
}

