#include "list.h"

struct ListElement
{
    int vertexTo;
    int length;
    ListElement *next;
};

struct LinkedList
{
   ListElement *head;
};

ListElement* createNewElement(int vertex, int length, ListElement* next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    newElement->length = length;
    newElement->vertexTo = vertex;
    return newElement;
}

LinkedList* createLinkedList()
{
    LinkedList *list = new LinkedList;
    list->head = createNewElement(0, 0, nullptr);
    return list;
}

void deleteLinkedList(LinkedList *list)
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

int valueFirst(LinkedList* list)
{
    if (list->head->next != nullptr)
    {
        return list->head->next->length;
    }
    else
    {
        return 0;
    }
}

int vertexFirst(LinkedList* list)
{
    return list->head->next->vertexTo;
}

LinkedList *addElementSortedList(int vertex, int length, LinkedList *list)
{
    ListElement *current = list->head->next;
    ListElement *previous = list->head;
    while ((current != nullptr) && (current->length < length))
    {
        previous = current;
        current = current->next;
    }

    previous->next = createNewElement(vertex, length, current);
    return list;
}

LinkedList *removeElementLinkedList(int vertex, LinkedList *list)
{
    if (list->head->next == nullptr)
    {
        return list;
    }
    ListElement *current = list->head->next;
    ListElement *previous = list->head;
    while ((current->next != nullptr) && (current->vertexTo != vertex))
    {
        previous = current;
        current = current->next;
    }
    if (current->vertexTo == vertex)
    {
        previous->next = current->next;
        delete current;
    }
    return list;
}


bool isEmpty(LinkedList *list)
{
    return list->head->next == nullptr;
}
