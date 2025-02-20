// Main.cpp

// Define
#define GLEW_STATIC

// Include libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <iostream>
#include <stdexcept>
// Include src files

// The main script
int main() {
	// Start GLFW
	glfwInit();
	// Tell GLFW the computer is using Wayland
	glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Windowed
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
//	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr);
	glfwMakeContextCurrent(window);
	// GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	// glGenBuffers
//	GLuint vertexBuffer;
//	glGenBuffers(1, &vertexBuffer);
//	printf("%u\n", vertexBuffer);
	// Command line printing
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	// Create Buffer
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	std::cout << "Vertex buffer ID: " << vertexBuffer << std::endl;

	// Setup for render

	// Render Loop

	while (!glfwWindowShouldClose(window)) {
		// Swap buffer
		glfwSwapBuffers(window);
		// GLFW EVENTS
		glfwPollEvents();
		// CLEAR
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		// RENDER
	}


	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}
