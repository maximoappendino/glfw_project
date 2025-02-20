cmake_minimum_required(VERSION 3.10)
project(glfw_project)

set(CMAKE_CXX_STANDARD 17)

# Find and link
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Include directories
include_directories(include)
include_directories(/usr/include)

# Source files
#add_executable(glfw_project src/main.cpp)
add_executable(
	glfw_project Source/Main.cpp
)

# Link libraries
target_link_libraries(glfw_project glfw OpenGL::GL GLEW::GLEW)
