#pragma once

/**
 * @brief The CalculatorSimple class Simple calculator class to calculate equation with two operands
 */

class CalculatorSimple
{
public:
    CalculatorSimple();
    /**
     * @brief getResult Returns result of calculating
     * @return Result, 0 by default, 0 in case of dividing by zero
     */
    int getResult();
    /**
     * @brief setFirstArgument Sets first argument of equation
     * @param value First argument of equation
     */
    void setFirstArgument(int value);
    /**
     * @brief setSecondArgument Sets second argument of equation
     * @param value Second argument of equation
     */
    void setSecondArgument(int value);
    /**
     * @brief setOperation Operation in equation
     * @param value Int value represents operation (defined in Operations Labels enum (plus = 0, minus = 1, multiply = 2, divide = 3))
     */
    void setOperation(int value);
private:
    void calc();
    int result;
    int firstArgument;
    int secondArgument;
    int operation;
};

