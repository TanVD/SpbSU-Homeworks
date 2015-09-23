#pragma once
#include <stdio.h>

struct StringATD;

StringATD* createStringATD();

char indexElement(StringATD* currentString, int index);

StringATD* createStringATD(FILE* file);

void deleteString(StringATD* string);

int lengthOfString(StringATD* currentString);

StringATD* subString(StringATD* currentString, int indexFirst, int length);

char* transformToChar(StringATD* currentString);

