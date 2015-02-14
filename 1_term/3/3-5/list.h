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

LinkedList* addElementLinkedList(int value, LinkedList* list);

void printLinkedList(LinkedList* list);

void deleteLinkedList(LinkedList* list);

LinkedList* addElementSortedList(int value, LinkedList* list);

LinkedList* removeElementLinkedList(int value, LinkedList* list);

LinkedList* convertToCyclicLinkedList(LinkedList* list);

void printLinkedCyclicList(LinkedList* list);

