using System;

namespace _C
{
    public class ListUnique : List
    {
        public override void Add(int value)
        {
            if (IsInList(value))
            {
                throw new AddExistedElementException();
            }
            else
            {
                base.Add(value);
            }
        }

        public override void Add(int value, int index)
        {
            if (!IsExistsIndex(index))
            {
                throw new OutOfIndexes();
            }
            else if (IsInList(value))
            {
                throw new AddExistedElementException();
            }
            else
            {
                base.Add(value, index);
            }
        }

        public override void  RemoveValue(int value)
        {
            if (!IsInList(value))
            {
                throw new DeleteNonExistedElement();
            }
            else
            {
                base.RemoveValue(value);
            }
        }

        public override void RemoveIndex(int index)
        {
            if (!IsExistsIndex(index))
            {
                throw new OutOfIndexes();
            }
            else
            {
                base.RemoveIndex(index);
            }
        }
    }

    public class AddExistedElementException : Exception
    {
        public AddExistedElementException()
        {
        }
    }

    public class DeleteNonExistedElement : Exception
    {
        public DeleteNonExistedElement()
        {
        }
    }

    public class OutOfIndexes : Exception
    {
        public OutOfIndexes()
        {
        }
    }
}

