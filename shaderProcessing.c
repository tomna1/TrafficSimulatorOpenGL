#include <stdlib.h>
#include <stdio.h.>
#include <string.h>

#include <GL/glew.h>

// Returns a string of the data store in a shader file. The string has to be
// freed otherwise there will be a memory leak.
static char* readShaderFromFile(const char* fileName) {
    // VISUAL STUDIO IS TELLING ME THAT THERE ARE ERRORS EVERYWHERE IN THIS
    // FUNCTION AND I HAD TO DISABLE SOMETHING JUST SO VISUAL STUDIO COULD
    // COMPILE MY CODE BUT IT WORKS SO IM NOT GOING TO TOUCH IT AGAIN.
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Cannot open shader file \"%s\"\n", fileName);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    char* output = (char*)malloc(size + 1);
    strcpy(output, "");
    char buffer[80] = "";
    rewind(file);

    while (fgets(&buffer, 80, file) != NULL) {
        strcat(output, &buffer);
        strcpy(&buffer, "");
    }

    // printf("Output from file \"%s\" : \n%s\n", fileName, output);
    fclose(file);
    return output;
}


// Will compile a shader and return an ID which references that compiled
// shader. If the shader fails to compile, it will print an error message
// to the standard output but wont really do any error handling.
static GLuint compileShader(GLuint type, const char* source) {
    // TODO : ERROR HANDLING IF type IS NOT A VALID TYPE.
    GLuint id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    GLint result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        char* message = (char*)malloc(sizeof(char) * length);
        glGetShaderInfoLog(id, length, &length, message);

        type == GL_VERTEX_SHADER ? printf("Vertex") : printf("Fragment");
        printf("Shader could not Compile. Error message: %s\n", message);
        glDeleteShader(id);
        free(message);

        return 0;
    }

    return id;
}

// Given a pointer to the source code of the vertex shader and a pointer to
// the source code of the fragment shader, it will compile these shaders
// and link them to a program and will then return the id of the program.
static GLuint createShaderProgram(const char *vertexShader, const char *fragmentShader) {
    GLuint shaderProgram = glCreateProgram();
    GLuint vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(shaderProgram, vs);
    glAttachShader(shaderProgram, fs);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    GLuint programLinkResult;
    glGetProgramiv(shaderProgram, GL_VALIDATE_STATUS, &programLinkResult);
    if (programLinkResult == GL_FALSE) {
        printf("Program failed to Validate.\n");
        // TODO: ACTUAL ERROR HANDLING
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    return shaderProgram;
}


// Setups up the shader program based on the shader files that are called at
// the start of the function. To read different shader files, this function
// has to be refactored.
GLuint setUpShaderProgram() {
    char* vertexShader = readShaderFromFile("vertexShader.shader");
    char* fragmentShader = readShaderFromFile("fragmentShader.shader");
    GLuint shaderProgram = createShaderProgram(vertexShader, fragmentShader);
    free(vertexShader);
    free(fragmentShader);
    glUseProgram(shaderProgram);
    glDeleteProgram(shaderProgram);
    return shaderProgram;
}
