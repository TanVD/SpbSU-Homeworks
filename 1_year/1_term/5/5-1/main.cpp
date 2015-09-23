#include <stdio.h>

int main()
{
    printf("This program will delete all repeating letter of every word after first.\n");
    char fileLocation[1000];
    printf("Enter file location: ");
    scanf("%s", fileLocation);
    FILE* text = fopen(fileLocation, "r");
    char stringInput[1000];

    while (fgets(stringInput, 1000, text) != nullptr)
    {

        int i = 0;

        while (stringInput[i] != '\n')
        {
            int k = 0;
            char stringOutput[1000] = {'\0'};
            while (stringInput[i] != ' ')
            {
                bool isFirst = true;
                for (int z = k; z >= 0; z--)
                {
                    if (stringInput[i] == stringOutput[z])
                        isFirst = false;
                }
                if (isFirst)
                {
                    stringOutput[k] = stringInput[i];
                    k++;
                }
                if (stringInput[i + 1] == '\n')
                {
                    break;
                }
                i++;
            }
            i++;
            printf("%s ", stringOutput);
        }
        printf("\n");

    }
}

