#include "phonebaselist.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct ListElement
{
    char phone[100] = {'\0'};
    char firstname[100] = {'\0'};
    char lastname[100] = {'\0'};
    ListElement *next;
};

struct LinkedList
{
   ListElement *head;
};

void fillField(char exit[], char input[])
{
    int i = 0;
    while (input[i] != '\0')
    {
        exit[i] = input[i];
        i++;
    }
    exit[i] = '\0';
}

ListElement* createNewElement(char phone[], char firstname[], char lastname[100], ListElement* next)
{
    ListElement *newElement = new ListElement;
    newElement->next = next;
    fillField(newElement->phone, phone);
    fillField(newElement->firstname, firstname);
    fillField(newElement->lastname, lastname);
    return newElement;
}

LinkedList* createLinkedList()
{
    LinkedList *list = new LinkedList;
    char guard[100] = {'\0'};
    list->head = createNewElement(guard, guard, guard, nullptr);
    return list;
}

bool isEqual(char arrayFirst[], char arraySecond[])
{
    int i = 0;
    while (((arrayFirst[i] != '\0') || (arraySecond[i] != '\0')) && (i < 100))
    {
        if (arrayFirst[i] != arraySecond[i])
            return false;
        i++;
    }
    return true;
}

LinkedList* addElementLinkedList(char phone[], char firstname[], char lastname[], LinkedList* list)
{
    ListElement *current = list->head;
    while ((current->next != nullptr) && (!isEqual(current->phone, phone)))
    {
        current = current->next;
    }
    if (isEqual(current->phone, phone))
    {
        printf("There has been already such phone in a phonebase");
        return list;
    }

    list->head->next = createNewElement(phone, firstname, lastname, list->head->next);
    return list;
}

void printElement(char element[])
{
    int i = 0;
    while (element[i] != '\0')
    {
        cout << element[i];
        i++;
    }

}

void printLinkedList(LinkedList *list)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        printElement(current->phone);
        printf(" - ");
        printElement(current->firstname);
        printf(" ");
        printElement(current->lastname);
        printf("\n");
    }
}

void syncLinkedList(LinkedList *list, FILE *phonebase)
{
    ListElement *current = list->head;
    while (current->next != nullptr)
    {
        current = current->next;
        fputs(current->firstname, phonebase);
        fputs("\n", phonebase);
        fputs(current->lastname, phonebase);
        fputs("\n", phonebase);
        fputs(current->phone, phonebase);
        fputs("\n", phonebase);

    }
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

void searchPhoneLinkedList(char phone[], LinkedList *list)
{
    if (list->head->next == nullptr)
    {
        printf("There is no phone in this list\n");
        return;
    }
    ListElement *current = list->head->next;
    while ((current->next != nullptr) && (!isEqual(current->phone, phone)))
    {
        current = current->next;
    }
    if (isEqual(current->phone, phone))
    {
        printf("Record ");
        printElement(current->phone);
        printf(" - ");
        printElement(current->firstname);
        printf(" ");
        printElement(current->lastname);
        printf("\n");
    }
    else
    {
        printf("No such phone.\n");
    }
    return;
}

void searchFirstnameLinkedList(char firstname[], LinkedList *list)
{
    int i  = 1;
    if (list->head->next == nullptr)
    {
        printf("There is no phone in this list\n");
        return;
    }
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        while ((current->next != nullptr) && (!isEqual(current->firstname, firstname)))
        {
            current = current->next;
        }
        if (isEqual(current->firstname, firstname))
        {
            printf("Record %d: ", i);
            printElement(current->phone);
            printf(" - ");
            printElement(current->firstname);
            printf(" ");
            printElement(current->lastname);
            printf("\n");
            i++;
        }
        current = current->next;

    }
    if (i == 1)
    {
        printf("No such phone");
    }
    return;
}

void searchLastnameLinkedList(char lastname[], LinkedList *list)
{
    int i  = 1;
    if (list->head->next == nullptr)
    {
        printf("There is no phone in this list\n");
        return;
    }
    ListElement *current = list->head->next;
    while (current != nullptr)
    {
        while ((current->next != nullptr) && (!isEqual(current->lastname, lastname)))
        {
            current = current->next;
        }
        if (isEqual(current->lastname, lastname))
        {
            printf("Record %d: ", i);
            printElement(current->phone);
            printf(" - ");
            printElement(current->firstname);
            printf(" ");
            printElement(current->lastname);
            printf("\n");
            i++;
        }
        current = current->next;
    }
    if (i == 1)
    {
        printf("No such phone");
    }
    return;
}
