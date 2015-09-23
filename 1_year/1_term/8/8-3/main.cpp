#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

bool** createGraph(int vertexNumber)
{
    bool **graph = new bool*[vertexNumber];
    for (int i = 0; i < vertexNumber; i++)
    {
        graph[i] = new bool[vertexNumber];
        for (int j = 0; j < vertexNumber; j++)
        {
            graph[i][j] = false;
        }
    }
    return graph;
}

void deleteGraph(bool** graph, int vertexNumber)
{
    for (int i = 0; i < vertexNumber; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}

void restoreComponent (bool** graph, int vertex, bool visited[], int vertexNumber)
{
    visited[vertex] = true;
    printf("%d ", vertex + 1);
    for (int i = 0; i < vertexNumber; i++)
    {
        if (graph[vertex][i])
        {
            if (!visited[i])
            {
                restoreComponent(graph, i, visited, vertexNumber);
            }
        }
    }
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
        bool **graph = createGraph(vertexNumber);
        for (int i = 0; i < edgeNumber; i++)
        {
            int vertexFrom = 0;
            int vertexTo = 0;
            in >> vertexFrom >> vertexTo;
            vertexFrom--;
            vertexTo--;
            graph[vertexFrom][vertexTo] = true;
            graph[vertexTo][vertexFrom] = true;
        }
        bool visited[vertexNumber];
        for (int i = 0; i < vertexNumber; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < vertexNumber; i++)
        {

            if (!visited[i])
            {
                printf("New component: ");
                restoreComponent(graph, i, visited, vertexNumber);
                printf("\n");
            }
        }
        deleteGraph(graph, vertexNumber);
    }
    delete[] fileLocation;
    return 0;
}
