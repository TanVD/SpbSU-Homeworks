#include <stdio.h>

int input()
{
	int number = 0;
	printf("Enter number equal to the sum we are seeking: ");
	scanf("%d", &number);
	return number;
}

void output(int myArray[], int lengthArray)
{
	for (int i = 0; i < lengthArray; i++)
		printf("%d ", myArray[i]);
	printf("\n");
}

void countSum(int activeSum, int lastNumber, int myArray[], int activeElement)
{
	for (int i = lastNumber; i <= activeSum; i++)
	{
		myArray[activeElement] = i;
		if (activeSum - i > 0)
			countSum(activeSum - i, i, myArray, activeElement + 1);
		else
			output(myArray, activeElement + 1);
	}
}


int main()
{

	const int maxSize = 10000;

	int number = input();
	int myArray[maxSize];
	int activeElement = 0;
	int lastNumber = 1; //starting subtracting with one
	printf("All sums are: \n");
	countSum(number, lastNumber, myArray, activeElement);

	return 0;
}
