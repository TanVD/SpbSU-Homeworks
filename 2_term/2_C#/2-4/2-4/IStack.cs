using System;

namespace Application
{
    public interface IStack<T>
    {
        void Push(T number) ;

        T Pop();

        T Top();

        bool IsEmpty();
    }
}

