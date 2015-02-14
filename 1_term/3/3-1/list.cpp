#include "list.h"
#include <stdio.h>

ListElement* createNewElement(int value, ListElement* next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    newElement->value = value;
    return newElement;
}

LinkedList* createLinkedList()
{
    LinkedList *list = new LinkedList;
    list->head = createNewElement(0, nullptr);
    return list;
}

ListElement* firstElement(LinkedList *list)
{
    return list->head->next;
}

ListElement* nextElement(ListElement* current)
{
    return current->next;
}

int valueElement(ListElement* current)
{
    return current->value;
}

ListElement* writeNextField (ListElement* current, ListElement* next)
{
    current->next = next;
    return current;
}

LinkedList* addElementLinkedList(int value, LinkedList* list)
{
    list->head->next = createNewElement(value, list->head->next);
    return list;
}

LinkedList* convertToCyclicLinkedList(LinkedList* list)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = list->head->next;
    return list;
}

void printLinkedList(LinkedList *list)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        printf("%d ", current->value);
    }
    printf("\n");
}


void deleteLinkedList( LinkedList *list)
{
    delete list->head;
    delete list;
}


void printLinkedCyclicList(LinkedList *list)
{
    ListElement *current = list->head->next;
    printf("%d ", current->value);
    while (current->next != list->head->next)
    {
        current = current->next;
        printf("%d ", current ->value);
    }
    printf("\n");
}
