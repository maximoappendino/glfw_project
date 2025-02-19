#define GLEW_STATIC // Define GLEW_STATIC for static linking
#include <GL/glew.h> // Include GLEW first
#include <GLFW/glfw3.h> // Then include GLFW (which includes OpenGL headers)
#include <iostream>
#include "Triangle.h"

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Use Wayland explicitly
    glfwWindowHint(GLFW_PLATFORM, GLFW_PLATFORM_WAYLAND);

    // Create a window with an OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Make OpenGL context current

    // Initialize GLEW
    glewExperimental = GL_TRUE; // Enable modern OpenGL features
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Check if GLEW initialized correctly and OpenGL functions are available
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    // Generate a buffer object to verify GLEW is working
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    std::cout << "Vertex buffer ID: " << vertexBuffer << std::endl;
///TRIANGLE
setupTriangle();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        // Render (clear screen with a color)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
renderTriangle();
        glfwSwapBuffers(window); // Swap buffers
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
