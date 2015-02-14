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

LinkedList* addElementLinkedList(int value, LinkedList* list)
{
    list->head->next = createNewElement(value, list->head->next);
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
    ListElement *following = list->head->next;
    ListElement *current = list->head;
    while ((current->next != nullptr) && (current->next != current))
    {
        delete current;
        current = following;
        following = current->next;
    }
    delete current;
    delete list;
}

LinkedList *addElementSortedList(int value, LinkedList *list)
{
    ListElement *current = list->head->next;
    ListElement *previous = list->head;
    while ((current != nullptr) && (current->value < value))
    {
        previous = current;
        current = current->next;
    }

    previous->next = createNewElement(value, current);
    return list;
}

LinkedList *removeElementLinkedList(int value, LinkedList *list)
{
    if(list->head->next == nullptr)
    {
        printf("There is no number in this list\n");
        return list;
    }
    ListElement *current = list->head->next;
    ListElement *previous = list->head;
    while ((current->next != nullptr) && (current->value != value))
    {
        previous = current;
        current = current->next;
    }
    if (current->value == value)
    {
        previous->next = current->next;
        delete current;
    }
    else
    {
        printf("No such element.\n");
    }
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
