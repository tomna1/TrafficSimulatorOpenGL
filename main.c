#define GLEW_STATIC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shaderProcessing.h"


/**
* Sets up all of the libraries needed and returns a pointer to the main
* window being used. The pointer is a NULL pointer if any of the 
* initialisations failed.
*/
GLFWwindow *setUp();


/**
* This is the callback function used when the window has been resized by the
* user.
*/
void framebufferSizeCallback(GLFWwindow *window, int width, int height);


/**
* The function in which all of the input code should be handled. This function
* should be called every render loop.
*/
void processInput(GLFWwindow *window);


int main(void)
{
    GLFWwindow *window = setUp();
    if (window == NULL) {
        return -1;
    }

    float trianglePosition[] = {
        -0.5f, -0.5,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    float rectanglePosition[] = {
        -0.25f, -0.5f, // bottom left
        -0.25f, 0.5f, // top left
        0.25f, 0.5f, // top right
        0.25f, -0.5f // bottom right
    };

    // buffer[0] is the triangle position and buffer[1] is the rectangle
    // position
    GLuint buffer[2];
    glGenBuffers(2, &buffer);
    
    glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
    glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), &rectanglePosition, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &trianglePosition, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    glEnableVertexAttribArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        processInput(window);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


GLFWwindow *setUp() {
    /* Initialize the library */
    if (!glfwInit()) {
        printf("GLFW failed to initialise.\n");
        return NULL;
    }
    
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window = glfwCreateWindow(960, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        printf("Window failed to open.\n");
        glfwTerminate();
        return NULL;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    /* Glew Initialisation*/
    if (glewInit() != GLEW_OK) {
        printf("GLEW failed to initialise.\n");
        glfwTerminate();
        return NULL;
    }
    
    printf("Currently using OpenGL Version %s\n", glGetString(GL_VERSION));

    // Sets the opengl viewport size and sets the framebufferSizeCallback
    // function to be called everytime the window is resized.
    glViewport(0, 0, 960, 720);
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

    // Sets the background colour of the window.
    glClearColor(0.5f, 0.1f, 0.1f, 1.0f);

    // read shaders from files and use them to create a shader program
    char *vertexShader = readShaderFromFile("vertexShader.shader");
    char *fragmentShader = readShaderFromFile("fragmentShader.shader");
    GLuint shaderProgram = createShaderProgram(vertexShader, fragmentShader);
    free(vertexShader);
    free(fragmentShader);
    glUseProgram(shaderProgram);
    glDeleteProgram(shaderProgram);

    return window;
}


void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    // glViewport resizes everything in the window to be able to fit within
    // The size of the window
    glViewport(0, 0, width, height);
}


void processInput(GLFWwindow *window) {
    // If the esc key is pressed then the window closes.
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
