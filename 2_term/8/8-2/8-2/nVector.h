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

    /**
     * @brief append Appends new object to vector
     * @param object Object to append
     */
    void append(T object)
    {
        array.append(object);
    }

    /**
     * @brief operator + Override + operator for vector to suppot n metric vector
     * @param vector Vector to add
     * @return Result of adding
     */
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

    /**
     * @brief operator - Override - operator for vector to suppot n metric vector
     * @param vector Vector to deduct
     * @return Result of deducting
     */
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

    /**
     * @brief operator *  Override * operator for vector to suppot n metric vector
     * @param number Number to multiply on vector
     * @return Result of multipling
     */
    NVector<T> operator*(int number)
    {
        NVector<T> result;
        for (int i = 0; i < this->size(); i++)
        {
            result.append(this->array[i] * number);
        }
        return result;
    }

    /**
     * @brief operator [] Returns object specified by index
     * @param index Index of object to get
     * @return Object specified by index
     */
    T operator[](int index)
    {
        return array[index];
    }

    /**
     * @brief isNull Returns true if vector filled with nulls only
     * @return True if null vector
     */
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

