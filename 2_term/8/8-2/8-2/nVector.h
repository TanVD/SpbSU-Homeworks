#pragma once
#include <QVector>

template<class T>
class NVector
{
public:
    NVector() : array(QVector<T>())
    {}

    NVector(QVector<T> vector) : array(vector)
    {}

    NVector(const NVector<T> &that)
    {
        this->array = that.array;
    }

    void append(T object)
    {
        array.append(object);
    }

    NVector<T> operator+(NVector<T> vector)
    {
        NVector<T> result;
        if (this->size() == vector.size())
            for (int i = 0; i < vector.size(); i++)
            {
                result.append(this->array[i] + vector.array[i]);
            }
        return result;
    }

    NVector<T> operator-(NVector<T> vector)
    {
        NVector<T> result;
        if (this->size() == vector.size())
            for (int i = 0; i < vector.size(); i++)
            {
                result.append(this->array[i] - vector.array[i]);
            }
        return result;
    }

    NVector<T> operator*(int number)
    {
        NVector<T> result;
        for (int i = 0; i < this->size(); i++)
        {
            result.append(this->array[i] * number);
        }
        return result;
    }

    T operator[](int index)
    {
        return array[index];
    }

    bool isNull()
    {
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

private:
    QVector<T> array;
    int size()
    {
        return array.size();
    }
};

