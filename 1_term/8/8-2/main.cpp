#include <iostream>
#include <fstream>

using namespace std;

int** createGraph(int vertexNumber)
{
    int **graph = new int*[vertexNumber];
    for (int i = 0; i < vertexNumber; i++)
    {
        graph[i] = new int[vertexNumber];
        for (int j = 0; j < vertexNumber; j++)
        {
            graph[i][j] = 0;
        }
    }
    return graph;
}

void deleteGraph(int** graph, int vertexNumber)
{
    for (int i = 0; i < vertexNumber; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
}

void copyArray (int* array1, int* array2, int length)
{
    for (int i = 0; i < length; i++)
    {
        array1[i] = array2[i];
    }
}

void dejkstraAlgorithm (int **graph, int vertexNumber)
{
    int firstVertex = 0;
    int** routes = createGraph(vertexNumber);
    int *indexRoutes = new int[vertexNumber];
    for (int i = 0; i < vertexNumber; i++)
    {
        indexRoutes[i] = 0;
    }

    int vertexFirst = 1;

    int lengthOfRoute[vertexNumber];
    bool visitedVertex[vertexNumber];
    bool isInfinity[vertexNumber];
    for (int i = 0; i < vertexNumber; i++)
    {
        lengthOfRoute[i] = 0;
        visitedVertex[i] = false;
        isInfinity[i] = true;
    }

    bool visitedAll = false;
    int minVertex = firstVertex;
    while (!visitedAll)
    {
        for (int i = 0; i < vertexNumber; i++)
        {
            if ((graph[minVertex][i] != 0) && ((graph[minVertex][i] + lengthOfRoute[minVertex] < lengthOfRoute[i])
                                               || (isInfinity[i])))
            {
                copyArray(routes[i], routes[minVertex], vertexNumber);
                indexRoutes[i] = indexRoutes[minVertex];
                routes[i][indexRoutes[i]] = minVertex + 1;
                indexRoutes[i]++;

                lengthOfRoute[i] = graph[minVertex][i] + lengthOfRoute[minVertex];
                isInfinity[i] = false;
            }
        }
        visitedVertex[minVertex] = true;
        visitedAll = true;
        int min = 0;
        minVertex = 0;
        for (int i = 0; i < vertexNumber; i++)
        {
            if (((min == 0 && lengthOfRoute[i] != 0) || (lengthOfRoute[i] < min)) && (!visitedVertex[i]) && (!isInfinity[i]))
            {
                min = lengthOfRoute[i];
                minVertex = i;
            }
        }
        for (int i = 0; i < vertexNumber; i++)
        {
            if (!visitedVertex[i])
            {
                visitedAll = false;
            }
        }
    }

    for (int i = 0; i < vertexNumber; i++)
    {
        if (i != vertexFirst - 1)
        {

            printf("Distance between %d city and %d city is %d\n", i + 1, vertexFirst, lengthOfRoute[i]);
            int j = 0;
            printf("Route is : ");
            while ( routes[i][j] != 0)
            {
                printf("%d ", routes[i][j]);
                j++;
            }

            printf ("%d\n", i + 1);
        }
    }

    int min = 0;
    int vertexCurrent = 0;
    printf("The order of occupying is ");
    for (int j = 1; j < vertexNumber; j++)
    {
        for (int i = 1; i < vertexNumber; i++)
        {
            if ((min == 0 && lengthOfRoute[i] != -1) || (lengthOfRoute[i] != -1 && lengthOfRoute[i] < min))
            {
                min = lengthOfRoute[i];
                vertexCurrent = i;
            }
        }
        printf("%d ", vertexCurrent + 1);
        min = 0;
        lengthOfRoute[vertexCurrent] = -1;
    }
    printf("\n");

    deleteGraph(routes, vertexNumber);
    delete[] indexRoutes;
}

int main()
{
    const int maxSize = 1000;
    char *fileLocation = new char[maxSize];
    cout << "Dieses Programm findet den kleinsten Weg zwischen den Stadten der Zukunft unserer Fuhrer" << endl;
    cout << "Geben Sie den Dateinamen: ";
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
        int **graph = createGraph(vertexNumber);
        for (int i = 0; i < edgeNumber; i++)
        {
            int vertexFrom = 0;
            int vertexTo = 0;
            int length = 0;
            in >> vertexFrom >> vertexTo >> length;
            vertexFrom--;
            vertexTo--;
            graph[vertexFrom][vertexTo] = length;
            graph[vertexTo][vertexFrom] = length;
        }
        dejkstraAlgorithm(graph, vertexNumber);

        deleteGraph(graph, vertexNumber);
    }
    delete[] fileLocation;
    return 0;
}

