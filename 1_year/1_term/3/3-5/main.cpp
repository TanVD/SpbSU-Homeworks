#include "list.h"
#include <stdio.h>

int main()
{
    bool isWorking = true;
    LinkedList *list = createLinkedList();
    printf("Enter your command.\n(Do not use letters)\n0 - exit;\n1 - add a value to sorted list;\n2 - remove a value from sorted list;\n3 - print list.\n");
    while (isWorking)
    {
        int choise = 0;
        scanf("%d", &choise);
        switch (choise)
        {

            case 0:
            {
                isWorking = false;
                break;
            }
            case 1:
            {
                int value = 0;
                printf("Enter your value: ");
                scanf("%d", &value);
                list = addElementSortedList(value, list);
                break;
            }
            case 2:
            {
                int value = 0;
                printf("Enter your value: ");
                scanf("%d", &value);
                list = removeElementLinkedList(value, list);
                break;
            }
            case 3:
            {
                printf("\nList is: ");
                printLinkedList(list);
                break;
            }
            default:
            {
                printf("Not correct input\n");
                break;
            }
        }
       if (isWorking)
           printf("\n\nEnter your command.\n0 - exit;\n1 - add a value to sorted list;\n2 - remove a value from sorted list;\n3 - print list.\n");
       else
           printf("\nList deleted.\nByebye\n");
    }
    deleteLinkedList(list);
    return 0;
}

