#include <stdio.h>
#include "BST.h"

int main()
{
    printf("This program will calculate you prefix equation.\nEnter location of file with equation: ");
    char fileLocation[100] = {'\0'};
    char c;
    int j = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            continue;
        fileLocation[j] = c;
        j++;
    }
    FILE* text = fopen(fileLocation, "r");
    char equation[100] = {'\0'};
    c = '\0';
    int i = 0;
    while (((c = getc(text)) != '\n') && (!feof(text)))
    {
        if (c == ' ')
            continue;
        equation[i] = c;
        i++;
    }

    BSTree *tree = createBSTree(equation);
    printStructBST(tree);
    printf("\n%.2f\n", countTree(tree));
    printInorderBST(tree);
    deleteBST(tree);
}

