#include <stdio.h>
#include "list.h"

int main()
{
    LinkedList *list = createLinkedList();
    int soldiersAmount = 0;
    int orderOfKill = 0;
    printf("This program will calculate which soldier will be the last in circle if every n soldier will commit suicide.\n");
    printf("Soldiers amount: ");
    scanf("%d", &soldiersAmount);
    printf("Every N will die. N: ");
    scanf("%d", &orderOfKill);
    for (int i = soldiersAmount; i > 0; i--)
    {
        addElementLinkedList(i, list);
    }
    ListElement *firstElementList = firstElement(list);
    list = convertToCyclicLinkedList(list);
    ListElement *current = firstElementList;
    ListElement *previous = firstElementList;
    int i = 0;
    while (nextElement(previous) != current)
        previous = nextElement(previous);

    while (nextElement(current) != current)
    {
        i++;
        if (i % orderOfKill == 0)
        {
            if (firstElementList == current)
                firstElementList = current->next;
            writeNextField(previous, nextElement(current));
            delete current;
            current = nextElement(previous);
        }
        else
        {
            current = nextElement(current);
            previous = nextElement(previous);
        }
    }
    printf("%d\n", valueElement(current));
    deleteLinkedList(list);
    return 0;
}
