#pragma once
#include <stdio.h>

struct ListElement;

struct LinkedList;

LinkedList* createLinkedList();

LinkedList* addElementLinkedList(char phone[], char firstname[], char lastname[], LinkedList* list);

void printLinkedList(LinkedList* list);

void syncLinkedList(LinkedList *list, FILE *phonebase);

void deleteLinkedList(LinkedList* list);

LinkedList* addElementSortedList(int value, LinkedList* list);

void searchPhoneLinkedList(char phone[], LinkedList *list);

void searchFirstnameLinkedList(char firstname[], LinkedList *list);

void searchLastnameLinkedList(char lastname[], LinkedList *list);

LinkedList* convertToCyclicLinkedList(LinkedList* list);

void printLinkedCyclicList(LinkedList* list);

