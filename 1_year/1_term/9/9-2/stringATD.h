#pragma once
#include <stdio.h>

struct StringATD;

StringATD* createStringATD();

StringATD* createStringATD(FILE* file);

void deleteString(StringATD* string);

StringATD* concutString(StringATD* firstString, StringATD* secondString);

StringATD* cloneString(StringATD* currentString);

bool isEqualString(StringATD* firstString, StringATD* secondString);

int lengthOfString(StringATD* currentString);

bool isEmptyString(StringATD* currentString);

StringATD* subString(StringATD* currentString, int indexFirst, int length);

char* transformToChar(StringATD* currentString);

char indexElement(StringATD* string, int index);

