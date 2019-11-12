cmake_minimum_required(VERSION 2.8)

# Name the project
project(Bomb)

# Add files to compile
set(	SOURCE_FILES 
	main.cpp 
	event_handling/EventHandler.cpp 
	event_handling/EventQueue.cpp
	peripherals/GPIO.cpp
	peripherals/PushButton.cpp
	peripherals/Timer.cpp
	state_handling/BombStateMachine.cpp
)

# Use C++11
ADD_DEFINITIONS(-std=c++11)

# Add executables to build
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

