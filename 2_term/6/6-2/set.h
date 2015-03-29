#pragma once

/**
 * @brief The LinkedList class Implements Linked List structure
 */
template <typename T>
class Set
{
public:
    Set() : head(nullptr), counter(0)
    {}
    ~Set();
    /**
     * @brief add Method adding new value in head of list
     * @param value Int value to be added
     */
    void add(T value)
    {
        if (!isExists(value))
        {
            head = new SetElement(value, head);
            counter++;
        }
    }
    /**
     * @brief remove Method deleting specific value in list
     * @param value Int value to be deleted
     * @return Return bool. True if value was found and deleted and false if value wasn't found
     */
    bool remove(T value);
    /**
     * @brief print Implementation of virtual method from IComparable. Prints elements of LinkedList.
     */
    bool isExists(T value);
    /**
     * @brief length Returns number of elements in set as int
     * @return Return int representing number of elements in set
     */
    int length()
    {
        return counter;
    }

    /**
     * @brief associationSets Associate two sets(this and param)
     * @param secondSet Second set to associate with this
     * @return Returns set which is association of two
     */
    Set<T> *associationSets(Set<T> *secondSet);
    /**
     * @brief intersectSets Intersection of two sets(this and param)
     * @param secondSet Second set to intersect with
     * @return Returns set which is intersection of two
     */
    Set<T> *intersectSets(Set<T> *secondSet);
private:
    class SetElement
    {
    public:
        T value;
        SetElement(T value, SetElement *lNext) : lNext(lNext), value(value)
        {}
        SetElement *lNext;
    };
    int counter;
    SetElement *head;
};

template <typename T>
Set<T>::~Set()
{
    SetElement *current = head;
    SetElement *toDelete = head;
    while (current != nullptr)
    {
        toDelete = current;
        current = current->lNext;
        delete toDelete;
    }
}

template <typename T>
bool Set<T>::remove(T value)
{
    SetElement *current  = head;
    SetElement *previous  = head;
    while (current != nullptr && current->value != value)
    {
        previous = current;
        current = current->lNext;
    }
    if (current != nullptr)
    {
        SetElement *toDelete = current;
        if (current != head)
            previous->lNext = current->lNext;
        else
            head = current->lNext;
        delete toDelete;
        counter--;
        return true;
    }
    return false;
}

template <typename T>
bool Set<T>::isExists(T value)
{
    SetElement *current  = head;
    while (current != nullptr && current->value != value)
    {
        current = current->lNext;
    }
    if (current != nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
Set<T> *Set<T>::associationSets(Set<T> *secondSet)
{
    Set<T> *resultSet = new Set<T>();
    SetElement *current  = head;
    while (current != nullptr)
    {
        resultSet->add(current->value);
        current = current->lNext;
    }
    current  = secondSet->head;
    while (current != nullptr)
    {
        resultSet->add(current->value);
        current = current->lNext;
    }
    return resultSet;
}

template <typename T>
Set<T> *Set<T>::intersectSets(Set<T> *secondSet)
{
    Set<T> *resultSet = new Set<T>();
    SetElement *current  = head;
    while (current != nullptr)
    {
        if (secondSet->isExists(current->value))
            resultSet->add(current->value);
        current = current->lNext;
    }
    return resultSet;
}
