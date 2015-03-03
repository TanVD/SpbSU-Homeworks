#include <iostream>
#include "sortedSet.h"
#include "linkedList.h"

using namespace std;

int main()
{
    cout << "Enter ! to add numbers to list.\nEnter * to create new list in set.\nEnter # to end.\nEnter commands: ";
    SortedSet* set = new SortedSet();
    LinkedList* newList = new LinkedList();
    while (true)
    {
       char command = 0;
       cin >> command;
       if (command == '!')
       {
           int number = 0;
           cin >> number;
           newList->add(number);
       }
       else if (command == '*')
       {
           set->add(newList);
           newList = new LinkedList();
       }
       else if (command == '#')
       {
           set->add(newList);
           break;
       }
    }
    cout << "Your sorted set: " << endl;
    set->print();
    delete set;
}

