#include <iostream>
#include <string.h>
#include "lexer.h"
#include <stdio.h>

using namespace std;

void shiftLeft(char* array, int length, int count, int position)
{
    for (int i = 0; i < count; i++)
    {
        int j = position;
        while (array[j] != '\0')
        {
            array[j] = array[j + 1];
            j++;
        }
        array[length - 1] = '\0';
    }
}

void shiftRight(char* array, int length, int count, int position)
{
    for (int i = 0; i < count; i++)
    {
        int j = length - 1;
        while (j != position)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[position] = '\0';
    }
}

bool recurseConstruct(char* lexemEquation, char* grammar[], char* equation, int index, int* placeOfMistake, int depth, int length)
{
    int indexLexEqNow = 0;
    while (lexemEquation[indexLexEqNow] != '\0')
    {
        indexLexEqNow++;
    }
    if (equation[indexLexEqNow] != '\0')
    {
        return false;
    }
    if (depth > 100)
        return false;
    while ((equation[index] == lexemEquation[index]) && lexemEquation[index] != '\0')
    {
        index++;
    }
    if (lexemEquation[index] == '\0' && equation[index] == '\0')
        return true;
    else if (lexemEquation[index] == '\0')
        return false;
    if (equation[index] == 'T')
    {
        depth++;
        for (int j = 0; j < 6; j++)
        {
            equation[index] = '\0';
            int slide = 0;
            for (int i = index; i < index + 3; i++)
            {
                if (grammar[j][i - index] != '\0')
                {
                    slide++;
                    if (equation[i] != '\0')
                        shiftRight(equation, length, 1, i);
                    equation[i] = grammar[j][i - index];
                }
            }
            if (recurseConstruct(lexemEquation, grammar, equation, index, placeOfMistake, depth, length))
                return true;
            shiftLeft(equation, length, slide - 1, index);
            equation[index] = 'T';
        }
    }
    if (index > *placeOfMistake)
        *placeOfMistake = index;
    return false;

}

int recurseTest(char* lexemEquation, char* grammar[], int length)
{
    char equation[length];
    memset(equation, '\0', length);
    equation[0] = 'T';
    int index = 0;
    int placeOfMistake = 0;
    if (recurseConstruct(lexemEquation, grammar, equation, index, &placeOfMistake, 0, length))
        return -1;
    return placeOfMistake;
}

bool isFromGrammatik(char c)
{
   return (c != '+' && c != '-' && c != '*' && c != '/' && c != 'A' && c != ' ');
}

bool isOperation(char c)
{
    return (c == '+') || (c == '-');
}

void inputArray(char* array)
{
    char c = '\0';
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        array[i] = c;
        i++;
    }
}

int main()
{
    const int lengthArray = 1000;
    cout << "Enter your equation to check: " << endl;
    char* equation = new char[lengthArray];
    memset(equation, '\0', lengthArray);
    inputArray(equation);
    char* lexemEquation = new char[lengthArray];
    memset(lexemEquation, '\0', lengthArray);
    int currentIndexLexem = 0;
    char lastSymbolEntered = '\0';
    while (equation[0] != '\0')
    {
        int index = 0;
        if (!((isOperation(equation[0])) && (lastSymbolEntered == 'A' || lastSymbolEntered == ')')))
            index = analyseLexem(equation);

        if (index > 0)
        {
            shiftLeft(equation, lengthArray, index, 0);
            lexemEquation[currentIndexLexem] = 'A';
            lastSymbolEntered = 'A';
            currentIndexLexem++;
        }
        else
        {   if (equation[0] != ' ')
            {
                lexemEquation[currentIndexLexem] = equation[0];
                lastSymbolEntered = equation[0];
                currentIndexLexem++;
            }
            shiftLeft(equation, lengthArray, 1, 0);
        }

    }
    delete[] equation;
    int i = 0;
    while (lexemEquation[i] != '\0')
    {
        if (!isFromGrammatik(equation[i]))
        {
            cout << "Not possible to recognize lexem number " << i + 1 << endl;
            delete[] lexemEquation;
            return 0;
        }
        if (lexemEquation[i] == ' ')
        {
            shiftLeft(lexemEquation, lengthArray, 1, i);
            continue;
        }
        i++;
    }
    cout << "Your lexem equation is " << lexemEquation << endl;

    char* arrayGram[6] = {"A\0\0", "(T)", "T+T", "T-T", "T*T", "T/T"};
    int placeOfMistake = recurseTest(lexemEquation, arrayGram, lengthArray);
    if (placeOfMistake == -1)
        cout << "Ok\n";
    else
        cout << "Wrong in " << placeOfMistake + 1 << " lexem" ;
    delete[] lexemEquation;
    return 0;
}

