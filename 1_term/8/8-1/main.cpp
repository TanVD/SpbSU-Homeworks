#include <iostream>
#include <fstream>

using namespace std;

void nameVertexes(bool **graph, int vertexFirst, char* names, int vertexNumber)
{
    names[vertexFirst] = 'a';
    int k = 'b';
    for (int i = 0; i < vertexNumber - 1; i++)
    {
        for (int j = 0; j < vertexNumber - 1; j++)
        {
            if ((graph[i][j]) && (names[i + 1] == '\0'))
            {
                names[i + 1] = k;
                k++;
            }
            if ((graph[i][j]) && (names[j + 1] == '\0'))
            {
                names[j + 1] = k;
                k++;
            }
        }
    }
}

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

int main()
{
    const int maxSize = 1000;
    char *fileLocation = new char[maxSize];
    cout << "Enter name of file:" << endl;
    cin >> fileLocation;

    ifstream in(fileLocation);

    if (!in.is_open())
    {
        cout << "Invalid file location" << endl;
        return 1;
    }
    else
    {
        int vertexNumber;
        int edgeNumber;
        in >> vertexNumber >> edgeNumber;
        bool **graph = createGraph(vertexNumber);
        for (int i = 0; i < edgeNumber; i++)
        {
            int vertexFrom;
            int vertexTo;
            in >> vertexFrom >> vertexTo;
            vertexFrom--;
            vertexTo--;
            graph[vertexFrom][vertexTo] = true;
        }
        int vertexFirst;
        in >> vertexFirst;
        char names[vertexNumber + 1];
        for (int j = 0; j < vertexNumber + 1; j++)
        {
            names[j] = '\0';
        }
        nameVertexes(graph, vertexFirst, names, vertexNumber + 1);
        printf("%s", names);
        for (int i = 1; i < vertexNumber + 1; i++)
        {
            cout << "Vertex number: " << i << " called as " << names[i] << endl;
        }
        in.close();
        deleteGraph(graph, vertexNumber);
    }
    delete fileLocation;
    return 0;
}

