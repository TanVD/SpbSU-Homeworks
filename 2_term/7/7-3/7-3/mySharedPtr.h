#pragma once

template <typename T>
class MySharedPtr
{
public:
    MySharedPtr(T* obj) : pointerData(new SharedData(obj, 1))
    {

    }

    /**
     * @brief MySharedPtr Constructor of copying
     * @param that Object to copy
     */
    MySharedPtr(const MySharedPtr &that) : pointerData(that.pointerData)
    {
        pointerData->linksCounter += 1;
    }

    ~MySharedPtr()
    {
        pointerData->linksCounter -= 1;
        if (pointerData->linksCounter == 0)
        {
            delete pointerData;
        }
    }

    T* operator->()
    {
        return pointerData->rawPointer;
    }

    T& operator* ()
    {
        return *(pointerData->rawPointer);
    }

    /**
     * @brief operator = Override assignment operator for smart pointer
     * @param that Object which is assigned
     * @return New object
     */
    MySharedPtr<T>& operator=(MySharedPtr<T> that)
    {
        this->~MySharedPtr();
        if (this->pointerData != that.pointerData)
        {
            this->pointerData = that.pointerData;
            this->pointerData->linksCounter += 1;
        }
        return *this;
    }

    /**
     * @brief copyCounter Return value of counter of linkss
     * @return Value of links to placed object
     */
    int copyCounter()
    {
        return pointerData->linksCounter;
    }

private:
    struct SharedData
    {
    public:
        T* rawPointer;
        int linksCounter;

        SharedData(T* rawPointer, int linksCounter) : rawPointer(rawPointer), linksCounter(linksCounter)
        {
        }

        ~SharedData()
        {
            delete rawPointer;
        }
    };

    SharedData* pointerData;
};
