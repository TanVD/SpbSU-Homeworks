#include <stdio.h>
#include "BST.h"
enum Commands
{
    addElement = 1,
    deleteElement = 2,
    findElement = 3,
    printTreeDescending = 4,
    printTreeAscending = 5,
    printStructTree = 6,
    endProgram = 7
};

int main()
{
    BSTree* tree = createBSTree();
    bool isWorking = true;
    while (isWorking)
    {
        printf("Enter a command.\n1 - add node at tree\n2 - delete node from tree\n3 - find node in a tree\n4 - print decending tree's values\n5 - print ascending tree's values\n6 - print struct of a tree\n7 - exit program\n");
        int instruction = 0;
        printf("Your command: ");
        scanf("%d", &instruction);
        switch (instruction)
        {
        case addElement:
        {
            int element = 0;
            printf("Your value to add: ");
            scanf("%d", &element);
            addNode(element, tree);
            break;
        }
        case deleteElement:
        {
            int element = 0;
            printf("Your value to delete: ");
            scanf("%d", &element);
            deleteNode(element, tree);
            break;
        }
        case findElement:
        {
            printf("Your value to find: ");
            int element = 0;
            scanf("%d", &element);
            if (isExists(element, tree))
                printf("Value exists\n");
            else
                printf("Value doesn't exist\n");
            break;
        }
        case printTreeDescending:
        {
            printf("Tree's values in a descending order:\n");
            printReverseInorderBST(tree);
            printf("\n");
            break;
        }
        case printTreeAscending:
        {
            printf("Tree's values in a ascending order:\n");
            printInorderBST(tree);
            printf("\n");
            break;
        }
        case printStructTree:
        {
            printf("Struct of your tree:\n");
            printStructBST(tree);
            printf("\n");
            break;
        }
        case endProgram:
        {
            printf("byebye");
            isWorking = false;
            break;
        }
        }
    }
    deleteBST(tree);
    return 0;
}

