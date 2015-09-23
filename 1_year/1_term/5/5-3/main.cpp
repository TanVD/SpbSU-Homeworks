#include <stdio.h>

int main()
{
    char fileLocation[1000];
    printf("This program will print all your comments from text file.\n");
    printf("Enter file location: ");
    scanf("%s", fileLocation);
    FILE* text = fopen(fileLocation, "r");
    char string[1000];
    bool isBlockComment = false;
    bool isQuote = false;

    if (text == nullptr)
    {
        return 1;
    }
    while (!feof(text))
    {
        fgets(string, 1000, text);
        if (!feof(text))
        {
            int i = 0;
            while (string[i] != '\n')
            {
                if (((string[i] == '/') && (string[i + 1] == '*') && (!isBlockComment))
                        || ((string[i] == '*') && (string[i + 1] == '/') && (isBlockComment)))
                {
                    isBlockComment = !isBlockComment;
                    i += 2;
                    continue;
                }
                if ((string[i] == '\"') && (string[i + 1] != '\"'))
                {
                    isQuote = !isQuote;
                    i++;
                    continue;
                }

                if ((string[i] =='/') && (string[i + 1] == '/') && (!isBlockComment) && (!isQuote))
                {
                    int j = i;
                    while (string[j] != '\n')
                    {
                        printf("%c", string[j]);
                        j++;
                    }
                    printf("\n");
                    break;
                }
                i++;
            }
        }
    }
    return 0;
}

