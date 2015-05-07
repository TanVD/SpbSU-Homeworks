#pragma once

/**
 * @brief The Queue class implements Queue structure
 */
template <typename T>
class Queue
{
public:
    Queue() : tail(nullptr), head(nullptr), counter(0)
    {}
    ~Queue();

    /**
     * @brief enqueue Method adding new value in a queue in according with a rule of Priority.
     * @param value template value to be added
     */
    void enqueue(T value, int priority);

    /**
     * @brief dequeue Method popping last value of queue (with the highest priority)
     * @return value with the highest priority.
     */
    T dequeue();

    /**
     * @brief length Returns number of elements in queue as int
     * @return return int representing number of elements in queue
     */
    int length()
    {
        return counter;
    }

private:
    class QueueElement
    {
    public:
        T value;
        int priority;
        QueueElement(T value, int priority, QueueElement *lPrevious, QueueElement *lNext) :
            lNext(lNext), lPrevious(lPrevious), value(value), priority(priority)
        {}
        QueueElement *lNext;
        QueueElement *lPrevious;
    };
    int counter;
    QueueElement *tail;
    QueueElement *head;
};

template <typename T>
Queue<T>::~Queue()
{
    if (counter > 0)
    {
        QueueElement *current = tail;
        while (current != nullptr)
        {
            QueueElement* toDelete = current;
            current = current->lNext;
            delete toDelete;
        }
    }
}

template <typename T>
void Queue<T>::enqueue(T value, int priority)
{
    QueueElement* current = tail;
    while (current != nullptr && current->priority < priority)
    {
        current = current->lNext;
    }
    if (current == nullptr && current == tail)//At least one element
    {
        tail = new QueueElement(value, priority, nullptr, nullptr);
        head = tail;
    }
    else if (current == nullptr)//Adding in head
    {
        head->lNext = new QueueElement(value, priority, head, nullptr);
        head = head->lNext;
    }
    else if (current == tail)//Adding in tail
    {
        tail->lPrevious = new QueueElement(value, priority, nullptr, tail);
        tail = tail->lPrevious;
    }
    else//All other variants
    {
        QueueElement* newElement = new QueueElement(value, priority, current->lPrevious, current);
        current->lPrevious->lNext = newElement;
        current->lPrevious = newElement;
    }
    counter++;
}

template <typename T>
T Queue<T>::dequeue()
{
    //This method is waiting for exception lecture
    QueueElement* current = head;
    if (counter > 1)
    {
        head = head->lPrevious;
        head->lNext = nullptr;
    }
    else
    {
        head->lPrevious = nullptr;
        head->lNext = nullptr;
    }
    counter--;
    T result = current->value;
    delete current;
    return result;
}
