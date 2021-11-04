# ObjectPong
My first ever game created entirely by myself. 
## Overview
The task was to create a Pong-like game without the use of any game engine. It was originally meant to be programmed in C# using the WPF Framework, however, as my Computer is currently running on Linux, I wanted to write a program which can run natively on my system.
There are multiple ways of achieving this, I chose to write a program in C++ using the Qt Framework. I like Open-Source software, and that is exactly what Qt is, so I began doing this school project in C++.

**The requirements were the following:**
* The game needs to use Keyboard input in order to move the pads.
* Both the ball and the pads need to be implemented as an object.
* Properties of these objects need to be changable via setter+getter
  in a way where variables used to change the object are `private`.

## Requirements for Building/Running
To simply run the application, you don't need anything.

To build the application, you need Qt5 and CMake version 2.8.11 or higher.
