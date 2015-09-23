#include <stdio.h>

int main()
{
    const int lenArray = 28;
    printf("This program will count number of a \"lucky tickets\". \nWait a moment.\n");
    int i = 0;
    int j = 0;
    int k = 0;
    int sumTicketArray[lenArray]={0};
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                sumTicketArray[i + j + k]++;
    int arrayIncrement = 0;
    int totalSumTickets = 0;
    for (arrayIncrement = 0; arrayIncrement < lenArray; arrayIncrement++)
    {
       sumTicketArray[arrayIncrement] *= sumTicketArray[arrayIncrement];
       totalSumTickets += sumTicketArray[arrayIncrement];
    }
    printf("That's it! Just a moment, isn't it?\nYour answer is: %d", totalSumTickets);
    return 0;
}
