#include <iostream>

using namespace std;

int markAllStudents(int array[], int i)
{
   if(array[i] > 3)
   {
       array[i] = markAllStudents(array, array[i]);
       return array[i];
   }
   else
   {
       return array[i];
   }
}

int main()
{
    cout << "This program will trace the original of all students copied works" << endl;
    cout << "Enter the number of students: ";
    int number;
    cin >> number;
    if (number < 4)
    {
        cout << "Invalid input";
    }
    int* array = new int[number + 1];
    for (int i = 1; i < 4; i++)
    {
        array[i] = i;
    }
    for (int i = 4; i < number + 1; i++)
    {
        int student;
        int copiedFromWhom;
        cout << "Enter number of student and from whom he copied his work: ";
        cin >> student >> copiedFromWhom;
        array[student] = copiedFromWhom;
    }
    for (int i = 4; i < number + 1; i++)
    {
        markAllStudents(array, i);
    }
    for (int i = 1; i < number + 1; i++)
    {
        cout << "Student " << i << " variant " << array[i] << endl;
    }
    return 0;
}

