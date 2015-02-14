#include "stackdouble.h"

struct StackElement
{
    double value;
    StackElement *next;
};

struct Stack
{
    StackElement *top;
};

StackElement* createNewElement(double value, StackElement* next)
{
    StackElement *newElement = new StackElement;
    newElement->next = next;
    newElement->value = value;
    return newElement;
}

Stack *createStack()
{
    Stack *stack = new Stack;
    stack->top = createNewElement(0, nullptr);
    return stack;
}

void push(Stack *stack, double value)
{
    stack->top->next = createNewElement(value, stack->top->next);
}

double pop(Stack *stack)
{
    double result = stack->top->next->value;
    StackElement *delElement = stack->top->next;
    stack->top->next = stack->top->next->next;
    delete delElement;
    return result;
}


double top(Stack *stack)
{
    if (stack->top->next != nullptr)
    {
        return stack->top->next->value;
    }
    else
    {
        return -1; // Used to write operation into empty stack
    }

}

bool isEmpty(Stack *stack)
{
    return stack->top->next == nullptr;
}

void deleteStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
    delete stack->top;
    delete stack;
}
