#pragma once

template <typename T>
class MySharedPtr
{
public:
    MySharedPtr(T* obj) : rawPointer(obj), linksCounter(new int(1))
    {
    }

    /**
     * @brief MySharedPtr Constructor of copying
     * @param that Object to copy
     */
    MySharedPtr(const MySharedPtr &that) : rawPointer(that.rawPointer), linksCounter(that.linksCounter)
    {
        *linksCounter += 1;
    }

    ~MySharedPtr()
    {
        *linksCounter -= 1;
        if (*linksCounter == 0)
        {
            delete rawPointer;
            delete linksCounter;
        }
    }

    T* operator->()
    {
        return rawPointer;
    }

    T& operator* ()
    {
        return *rawPointer;
    }

    /**
     * @brief operator = Override assignment operator for smart pointer
     * @param that Object which is assigned
     * @return New object
     */
    MySharedPtr<T>& operator=(MySharedPtr<T> that)
    {
        if (this->rawPointer != that.rawPointer)
        {
            this->linksCounter = that.linksCounter;
            this->rawPointer = that.rawPointer;
            *(this->linksCounter) += 1;
        }
        return *this;//todo
    }

    /**
     * @brief copyCounter Return value of counter of linkss
     * @return Value of links to placed object
     */
    int copyCounter()
    {
        return *linksCounter;
    }

private:
    T* rawPointer;
    int* linksCounter;
};
