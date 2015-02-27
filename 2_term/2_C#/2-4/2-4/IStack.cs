using System;

namespace Application
{
    interface IStack <T>
    {
        void Push(T number) ;

        T Pop();

        T Top();

        bool IsEmpty();
    }
}

