#include "matrix.h"
#include <iostream>

Matrix::Matrix(int size) : size(size)
{
    matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
    }
    std::cout << "Enter matrix: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int element;
            std::cin >> element;
            matrix[i][j] = element;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int Matrix::getByIndex(int width, int height)
{
    return matrix[width][height];
}

