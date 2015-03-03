#pragma once
/**
  *@mainpage The IComparable class makes possible to create structures of smth that can compare each to each
  */


/**
 * @brief The IComparable class Interface of comparator with counter field for comparation
 */

class IComparable
{
public:
    /**
      * @brief ~IComparable Virtual destructor of inteface
      */
     virtual ~IComparable() {};
    /**
      * @brief compareTo Virtual method of comparation which implements in descendant of IComparable
      * @param that IComparable object brought to compare with
      * @return Int (1, 0, -1) 1 if this > that, 0 if this == that, -1 if this < that
      */
     virtual int compareTo(IComparable* that) = 0;
    /**
      * @brief length Public method for descendant to get value of counter
      * @return Int value of counter
      */
     int length() const
     {
         return counter;
     }
     /**
      * @brief print Virtual method to print IComparable object
      */
     virtual void print() = 0;
 protected:
     int counter = 0;

};
