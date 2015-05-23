#pragma once
/**
 * @brief The Matrix class Makes it easier to work with int matrix
 */
class Matrix
{
public:
    /**
     * @brief Matrix Creates int matrix
     * @param size Matrix will be size * size of int numbers
     */
    Matrix(int size);
    /**
     * @brief Destructor of matrix
     */
    ~Matrix();
    /**
     * @brief getByIndex Getting number placed in width*height cell
     * @param width Width of cell
     * @param height Height of cell
     * @return Returns int number placed in chosen cell
     */
    int getByIndex(int width, int height);
    /**
     * @brief getSize Return height or width of matrix (equal because matrix is square)
     * @return Int number - size of matrix
     */
    int getSize();
private:
    int** matrix;
    int size;
};

