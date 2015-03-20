using System;

namespace _C
{
    public class ListUnique : List
    {
        public override void Add(int value)
        {
            if (IsExists(value))
            {
                throw new AddExistedElementException();
            }
            else
            {
                base.Add(value);
            }
        }

        public override void Remove(int value)
        {
            if (!IsExists(value))
            {
                throw new DeleteNonExistedElement();
            }
            else
            {
                base.Remove(value);
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
}

