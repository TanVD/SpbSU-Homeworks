#include "phonebaselist.h"
#include <stdio.h>

enum commands {exit = 0, addElement = 1, search = 2, searchPhone = 1, searchFirstname = 2, searchLastname = 3, printBase = 3, syncFile = 4};

void inputCharArray(char array[])
{
    char c;
    int i = 0;
    c = getchar();
    if (c != '\n')
    {
        array[i] = c;
        i++;
    }
    while ((c = getchar()) != '\n')
    {
            array[i] = c;
            i++;
    }
    array[i] = '\0';
}

void wipeOutNewLines(char array[])
{
    int i = 0;
    while (array[i] != '\0')
    {
        if (array[i] == '\n')
            array[i] = '\0';
        i++;
    }
}

int main()
{
    bool isWorking = true;
    char firstname[100];
    char lastname[100];
    char phone[100];
    char fileLocation[100];

    printf("Enter the way to your phonebase location or way to the location you want phonebase to settle: ");
    inputCharArray(fileLocation);
    LinkedList *list = createLinkedList();
    FILE *phonebase = fopen(fileLocation, "r");
    if (phonebase != nullptr)
    {
        while(!feof(phonebase))
        {
            fgets(firstname, 100, phonebase);
            wipeOutNewLines(firstname);
            fgets(lastname, 100, phonebase);
            wipeOutNewLines(lastname);
            fgets(phone, 100, phonebase);
            wipeOutNewLines(phone);
            if (!feof(phonebase))
                addElementLinkedList(phone, firstname, lastname, list);
        }
    }
    else
    {
        printf("Phonebase not found. It will be created if you will try to sync base.\n");
    }

    printf("Phonebase\nEnter your command.\n(Do not use letters)\n0 - exit;\n1 - add a record to list;\n2 - find record in list;\n3 - print list;\n4 - save list to file.\n\n");
    while (isWorking)
    {
        int choice = 0;
        scanf("%d", &choice);
        switch (choice)
        {

            case exit:
            {
                isWorking = false;
                break;
            }
            case addElement:
            {
                printf("Enter your phone: ");
                inputCharArray(phone);
                printf("Enter firstname: ");
                inputCharArray(firstname);
                printf("Enter lastname: ");
                inputCharArray(lastname);
                list = addElementLinkedList(phone, firstname, lastname, list);
                break;
            }
            case search:
            {
                int choiceSearch = 0;
                printf("Enter your command.\n1 - find a record by phone\n2 - find a record by firstname\n3 - find a record by lastname\n");
                scanf("%d", &choiceSearch);
                switch (choiceSearch)
                {
                    case searchPhone:
                    {
                        inputCharArray(phone);
                        searchPhoneLinkedList(phone, list);
                        break;
                    }
                    case searchFirstname:
                    {
                        inputCharArray(firstname);
                        searchFirstnameLinkedList(firstname, list);
                        break;
                    }
                    case searchLastname:
                    {
                        inputCharArray(lastname);
                        searchLastnameLinkedList(lastname, list);
                        break;
                    }
                    default:
                    {
                        printf("Non-valid input.");
                        break;
                    }

                }
                break;
            }
            case printBase:
            {
                printf("\nYour base\n");
                printLinkedList(list);
                break;
            }
            case syncFile:
            {
                printf("Syncronization is queued and will be made after the exit.");
                if (phonebase != nullptr)
                    fclose(phonebase);
                phonebase = fopen(fileLocation, "w");
                syncLinkedList(list, phonebase);
                break;
            }
            default:
            {
                printf("Not correct input\n");
                break;
            }
        }
       if (isWorking)
           printf("\n\nEnter your command.\n(Do not use letters)\n0 - exit;\n1 - add a record to list;\n2 - find record in list;\n3 - print list;\n4 - save list to file.\n");
       else
           printf("\nList deleted.\nByebye\n");
    }
    deleteLinkedList(list);
    fclose(phonebase);
    return 0;
}

