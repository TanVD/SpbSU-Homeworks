#pragma once
#include "stringATD.h"
struct ListElement
{
    StringATD* string;
    ListElement *next;
    int counter;
};

struct LinkedList
{
   ListElement *head;
};

LinkedList* createList();

LinkedList* addList(StringATD* string, LinkedList* list);

void deleteLinkedList(LinkedList* list);





