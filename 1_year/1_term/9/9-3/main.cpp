#include <iostream>
#include <fstream>
#include "list.h"
#include <stdio.h>

using namespace std;

void clearNotNeeded(LinkedList* graph[], int vertex, int vertexNumber)
{
    for (int i = 0; i < vertexNumber; i++)
    {
        removeElementLinkedList(vertex, graph[i]);
    }
}

void deleteGraph(LinkedList** graph, int vertexNumber)
{
    for (int i = 0; i < vertexNumber; i++)
    {
        deleteLinkedList(graph[i]);
    }
    delete[] graph;
}

int main()
{
    const int maxSize = 1000;
    char *fileLocation = new char[maxSize];
    printf("This program will find all components of connection in your matrix\n");
    cout << "Enter name of file: ";
    cin >> fileLocation;
    ifstream in(fileLocation);

    if (!in.is_open())
    {
        cout << "Invalid file location" << endl;
        return 1;
    }
    else
    {
        int vertexNumber = 0;
        int edgeNumber = 0;
        in >> vertexNumber >> edgeNumber;
        LinkedList** graph = new LinkedList*[vertexNumber];
        for (int i = 0; i < vertexNumber; i++)
        {
            graph[i] = createLinkedList();
        }
        for (int i = 0; i < edgeNumber; i++)
        {
            int vertexFrom = 0;
            int vertexTo = 0;
            int length = 0;
            in >> vertexFrom >> vertexTo >> length;
            vertexFrom--;
            vertexTo--;
            addElementSortedList(vertexTo, length, graph[vertexFrom]);
            addElementSortedList(vertexFrom, length, graph[vertexTo]);
        }
        bool visited[vertexNumber];
        for (int i = 0; i < vertexNumber; i++)
        {
            visited[i] = false;
        }
        int min = 1;
        int minVertex = 0;
        while (min != 0)
        {
            visited[minVertex] = true;
            clearNotNeeded(graph, minVertex, vertexNumber);
            minVertex = 0;
            min = 0;
            int fromWhich = 0;
            for (int i = 0; i < vertexNumber; i++)
            {
                if (!isEmpty(graph[i]) && ((valueFirst(graph[i]) < min || min == 0)) && (visited[i]))
                {
                    fromWhich = i;
                    min = valueFirst(graph[i]);
                    minVertex = vertexFirst(graph[i]);
                }
            }
            if (min != 0)
            {
                printf("Component of the spanning tree is %d - %d\n", fromWhich + 1, minVertex + 1);
            }
        }
        deleteGraph(graph, vertexNumber);
    }
    delete[] fileLocation;
    in.close();
    return 0;
}

