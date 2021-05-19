set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

cmake_minimum_required(VERSION 3.5)

project(Snake) # Set variable PROJECT_NAME

add_executable(output) # Create a executable from main.cpp

target_include_directories(output 
		PUBLIC 
		./
		./SDL_FULL/include/
		)

link_directories(output
		PUBLIC
		./SDL_FULL/x86/
		)

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
