#pragma once

struct ListElement;

struct LinkedList;

LinkedList* createLinkedList();

void deleteLinkedList(LinkedList* list);

LinkedList *addElementSortedList(int vertex, int length, LinkedList *list);

LinkedList* removeElementLinkedList(int vertex, LinkedList* list);

bool isEmpty(LinkedList* list);

int valueFirst(LinkedList* list);

int vertexFirst(LinkedList* list);

