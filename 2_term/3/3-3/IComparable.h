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
      * @brief ~IComparable Virtual destructor of interface
      */
     virtual ~IComparable() {};
    /**
      * @brief compareTo Virtual method of comparation which implements in descendant of IComparable
      * @param that IComparable object brought to compare with
      * @return Int (1, 0, -1) 1 if this > that, 0 if this == that, -1 if this < that
      */
     virtual int compareTo(IComparable* that) = 0;
    /**
      * @brief length Virtual method on result of which comparation decision based
      * @return Int value for comparation
      */
     virtual int length() = 0;
     /**
      * @brief print Virtual method to print IComparable object
      */
     virtual void print() = 0;

};
