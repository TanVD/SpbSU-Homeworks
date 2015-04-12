using System;

namespace _C
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var eventLoop = new EventLoop();
            eventLoop.LeftHandler += (Object sender, EventArgs EventArgs) => {if (Console.CursorLeft > 1) Console.CursorLeft -= 1;};
            eventLoop.RightHandler += (Object sender, EventArgs EventArgs) =>{if (Console.CursorLeft < Console.BufferWidth - 1) Console.CursorLeft += 1;};
            eventLoop.DownHandler += (Object sender, EventArgs EventArgs) => {if (Console.CursorTop < Console.BufferHeight - 1) Console.CursorTop += 1;};
            eventLoop.UpHandler += (Object sender, EventArgs EventArgs) =>{if (Console.CursorTop > 1) Console.CursorTop -= 1;};
            eventLoop.Run();
        }
    }
}
