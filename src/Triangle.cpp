#include "Triangle.h"
#include <GL/glew.h>

// Vertex data for a triangle
float vertices[] = {
    -0.5f, -0.5f, 0.0f, // Bottom-left
     0.5f, -0.5f, 0.0f, // Bottom-right
     0.0f,  0.5f, 0.0f  // Top-center
};

// Vertex Buffer Object (VBO) and Vertex Array Object (VAO)
GLuint VBO, VAO;

void setupTriangle() {
    // Generate and bind the VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind the VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Specify the vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the VAO (optional but recommended)
    glBindVertexArray(0);
}

void renderTriangle() {
    // Bind the VAO and draw the triangle
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
