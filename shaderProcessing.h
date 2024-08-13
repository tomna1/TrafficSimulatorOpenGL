#ifndef SHADER___H
#define SHADER___H

#include <GL/glew.h>

// Given a pointer to the source code of the vertex shader and a pointer to
// the source code of the fragment shader, it will compile these shaders
// and link them to a program and will then return the id of the program.
GLuint createShaderProgram(const char* vertexShader, const char* fragmentShader);

// Returns a string of the data store in a shader file. The string has to be
// freed otherwise there will be a memory leak.
char* readShaderFromFile(const char* fileName);


#endif
