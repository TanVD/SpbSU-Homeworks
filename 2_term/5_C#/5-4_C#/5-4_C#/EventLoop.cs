using System;

namespace _C
{
    public class EventLoop
    {
        public event EventHandler<EventArgs> LeftHandler = (sender, EventArgs) => {};
        public event EventHandler<EventArgs> RightHandler = (sender, EventArgs) => {};
        public event EventHandler<EventArgs> DownHandler = (sender, EventArgs) => {};
        public event EventHandler<EventArgs> UpHandler = (sender, EventArgs) => {};

        public void Run()
        {
            while (true)
            {
                var key = Console.ReadKey(true);
                switch (key.Key)
                {
                    case (ConsoleKey.LeftArrow):
                        {
                            LeftHandler(this, EventArgs.Empty);
                            break;
                        }
                    case (ConsoleKey.RightArrow):
                        {
                            RightHandler(this, EventArgs.Empty);
                            break;
                        }
                    case (ConsoleKey.DownArrow):
                        {
                            DownHandler(this, EventArgs.Empty);
                            break;
                        }
                    case (ConsoleKey.UpArrow):
                        {
                            UpHandler(this, EventArgs.Empty);
                            break;
                        }
                }
            }
        }
    }
}

