# Snake
![Preview of game](preview/Snake.gif)

A simple game of snake in C++ and SDL featuring absolutely nothing new. 

## Why this exists
This is the very first official game I have ever developed back in 2018 as a starter project. Most of the code and its bad practices remains unchanged due to laziness and its historical significance, though the project structure has been completely revamped to automatically install SDL dependencies for Linux, work with CMake, and officially have a GNU GPL v3 License.

# Compiling on Linux
## Requirements
This project uses CMake in order to generate a make file. Install CMake through whatever means necessary, though the easiest would be using `sudo apt-get install cmake` on the command line. 

## Compiling
To compile this project simply run `installSDL.bash` to download the required dependencies then `compile.bash` to compile an executable into `build/`. It's as easy as that! 

NOTE: Even if you have SDL installed on your system via `sudo apt-get install libsdl2-2.0`, you still have to run `installSDL.bash` as this project installs SDL only in its root directory, not the system. 

# Compiling on Windows
## Requirements
Installing prerequisites on Windows is a bit more complicated. First, download the binary executable of [CMake](https://cmake.org/) and install it. Be sure to install the executable that matches your system architecture.

After that, create a folder named `SDL_FULL` in the root directory of this project and put two folders named `include` and `x86` inside it; Here is where you put the header files of SDL2, SDL2_image, and SDL_tff in `include` and their x86 .lib files into `x86`. If you plan on using Visual Studio for this, you can follow these steps:
* Get the SDL2.zip archive from [here](https://www.libsdl.org/release/SDL2-devel-2.0.14-VC.zip)
* Get the SDL2_image.zip archive from [here](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip)
* Get the SDL2_ttf.zip archive from [here](https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip)
* For each archive, unzip the contents of their `include` folder into `SDL_FULL/include` and `lib/x86` folder into `SDL_FULL/x86`
* Move all the .dll files into a separate folder at the root of the project; This is where your executable will run. 

## Compiling
To compile this project, you need to use CMake and your prefered compiler to generate a x86 version of your solution / executable. In some compilers and IDE's more work is needed, such as in Visual Studio where you have to manually specicify the library path of SDL as being `SDL_FULL/x86`.

After this, the compiled executable must be put into ANY folder in the root directory along with the aforementioned .dll files of SDL2. After this, you can run the game :)
