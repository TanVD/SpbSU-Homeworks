using System;

namespace Application
{
    interface IStack
    {
        void Push(double number) ;

        double Pop();

        double Top();

        bool IsEmpty();
    }
}

