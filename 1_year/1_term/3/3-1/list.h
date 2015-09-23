#pragma once

struct ListElement
{
    int value;
    ListElement *next;
};

struct LinkedList
{
   ListElement *head;
};

LinkedList* createLinkedList();

ListElement* firstElement(LinkedList* list);

ListElement* nextElement(ListElement* current);

int valueElement(ListElement* current);

ListElement* writeNextField (ListElement* current, ListElement* next);

LinkedList* addElementLinkedList(int value, LinkedList* list);

void printLinkedList(LinkedList* list);

void deleteLinkedList(LinkedList* list);

LinkedList* convertToCyclicLinkedList(LinkedList* list);

void printLinkedCyclicList(LinkedList* list);
