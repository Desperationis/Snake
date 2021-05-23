set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

cmake_minimum_required(VERSION 3.5)

project(Snake VERSION 1.1.2)

if (WIN32)
	link_directories(${CMAKE_SOURCE_DIR}/SDL_FULL/x86/) # Call before to make sure VS detects it
endif()

if(UNIX)
	find_package(SDL2 REQUIRED)
endif()

add_executable(output)

target_include_directories(output 
		PUBLIC 
		./
		./SDL_FULL/include/
		)

if (WIN32)
	target_include_directories(output PUBLIC ./SDL_FULL/include)
endif()

if(UNIX)
	target_include_directories(output PUBLIC ${SDL2_INCLUDE_DIRS})
endif()


target_sources(output 
		PUBLIC 
		main.cpp
		Button.cpp
		fruit.cpp
		Game.cpp
		Grid.cpp
		Input.cpp
		Menu.cpp
		piece.cpp
		SceneManager.cpp
		Snek.cpp
		Text.cpp
		TextureManager.cpp
		
		)

target_link_libraries(output 
		SDL2main
		SDL2_image
		SDL2
		SDL2_ttf
		)
