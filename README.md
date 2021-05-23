# Snake
![Preview of game](preview/Snake.gif)

A simple game of snake in C++ and [SDL](https://www.libsdl.org/) featuring absolutely nothing new. 

## Why this exists
This is the very first official game I have ever developed back in 2018 as a starter project. Most of the code and its bad practices remains unchanged due to laziness and its historical significance, though the project structure has been completely revamped to automatically install SDL dependencies for Linux, work with CMake, and officially have a GNU GPL v3 License.

# Compiling on Linux
This project uses CMake in order to generate a make file. Install CMake through whatever means necessary, though the easiest would be using `sudo apt-get install cmake` on the command line. 

In addition to this, you must install the dev versions of [SDL2](https://www.libsdl.org/), [SDL2_image](https://www.libsdl.org/projects/SDL_image/), and [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/). On Debian, this can be done by calling `sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev`. 

After that, you can compile this project by simply running `compile.bash` to compile an executable into `executable/`. It's as easy as that! 

# Compiling on Windows
## Requirements
Installing prerequisites on Windows is a bit more complicated. First, download the binary executable of [CMake](https://cmake.org/) and install it. Be sure to install the executable that matches your system architecture.

After that, create a folder named `SDL_FULL`. In that folder, create a two folders named `include` and `x86`. After that, follow these steps
* Get the `SDL2-devel-2.0.x` archive from [here](https://www.libsdl.org/release/)
* Get the `SDL2_image-devel-2.0.x` archive from [here](https://www.libsdl.org/projects/SDL_image/release/)
* Get the `SDL2_ttf-devel-2.0.x` archive from [here](https://www.libsdl.org/projects/SDL_ttf/release/)
* For each archive, unzip the contents of their `include` folder into `SDL_FULL/include` and `lib/x86` folder into `SDL_FULL/x86`
* Move all the .dll files into a separate folder at the root of the project; This is where your executable will run. 

## Compiling
To compile this project, you need to use CMake and your prefered compiler to generate a x86 (32-bit) version of your solution / executable. 

After this, the compiled executable must be put into ANY folder in the root directory of the project along with the aforementioned .dll files of SDL2. After this, you can run the game :)
