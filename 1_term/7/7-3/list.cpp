#include "list.h"
#include <iostream>
#include "stringATD.h"

ListElement* createNewElement(StringATD* string, ListElement* next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    newElement->string = string;
    newElement->counter = 1;
    return newElement;
}

LinkedList* createList()
{
    LinkedList *list = new LinkedList;
    list->head = createNewElement(nullptr, nullptr);
    return list;
}

ListElement* findElement(StringATD* string, LinkedList *list)
{
    ListElement *current = list->head->next;
    while ((current != nullptr) && (!isEqualString(string, current->string)))
    {
        current = current->next;
    }
    return current;
}

LinkedList* addList(StringATD* string, LinkedList* list)
{
    ListElement* current = findElement(string, list);
    if (current == nullptr)
        list->head->next = createNewElement(string, list->head->next);
    else
        current->counter++;
    return list;
}

void deleteLinkedList(LinkedList *list)
{
    ListElement *following = list->head->next;
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        if (current->string != nullptr)
            deleteString(current->string);
        delete current;
        current = following;
        following = current->next;
    }
    delete current;
    delete list;
}
