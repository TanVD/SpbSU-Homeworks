#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomizeRand()
{
    long timeSeed = time(NULL);
    srand(timeSeed);
}


int main()
{
    printf("It is \"Bulls and Cows\" game. The computer will take random 4 digit number.\n");
    printf("You will try to guess number. If it is cow than you've guessed number but not a position.\nIf it is bull than you've guessed number and position.\n");

    randomizeRand();

    char secretNumber[4] = {0};
    int myArray[4] = {0};
    int j = 0;
    while (j < 4)
    {
        bool unique = false;
        int digit = rand() % 10;
        for(int i = 0; i <= j; i++)
        {
            if (myArray[i] == digit)
              break;
            if (i == j)
                unique = true;
        }
        if (unique)
        {
            myArray[j]=digit;
            secretNumber[j] = digit + '0';
            ++j;
        }
     }
    //printf("%s", secretNumber);

    char guessedNumber[4] = {0};
    int cow = 0;
    int bull = 0;
    while (bull != 4)
    {
        printf("Print your guess: ");
        scanf("%s", guessedNumber);
        cow = 0;
        bull = 0;
        for (int i = 0; i < 4; i++)
        {
             for (int j = 0; j < 4; j++)
            {

                if ((secretNumber[i] == guessedNumber[j]) && ( i == j))
                {
                    bull++;
                    break;
                }
                if ((secretNumber[i] == guessedNumber[j]) && ( i != j))
                {
                    cow++;
                    break;
                }

            }
        }
        printf("%d bulls; %d cows \n", bull, cow);

    }
    printf("You win!");
    printf("%s", secretNumber);
    return 0;
}
