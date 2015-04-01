using System;

namespace _C
{
    /// <summary>
    /// Class implementing handler of events with event loop
    /// </summary>
    public class EventLoop
    {
        /// <summary>
        /// Occurs when left arrow pressed.
        /// </summary>
        public event EventHandler<EventArgs> LeftHandler = (sender, EventArgs) => {};

        /// <summary>
        /// Occurs when right arrow pressed.
        /// </summary>
        public event EventHandler<EventArgs> RightHandler = (sender, EventArgs) => {};

        /// <summary>
        /// Occurs when down arrow pressed.
        /// </summary>
        public event EventHandler<EventArgs> DownHandler = (sender, EventArgs) => {};

        /// <summary>
        /// Occurs when up arrow pressed.
        /// </summary>
        public event EventHandler<EventArgs> UpHandler = (sender, EventArgs) => {};

        /// <summary>
        /// Run event loop with handler of keyboard arrows.
        /// </summary>
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

