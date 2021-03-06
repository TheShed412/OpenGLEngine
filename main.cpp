#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <math.h>
#include <time.h>

// my shit
// #include "headers/initShader.h"
#include "headers/Shader.hpp"
#include "headers/ObjectLoader.hpp"

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

void init(void);

// The MAIN function, from here we start the application and run the game loop
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Testing");
    glewInit();
    init();
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

void init(void) 
{
    // GLuint program = initShader("shaders/vshader.glsl", "shaders/fshader.glsl");
    // glUseProgram(program);
    Shader shaders("shaders/vshader.glsl", "shaders/fshader.glsl");
    shaders.use();
    ObjectLoader objLoader;
    vector<vec3> verts;
    vector<vec2> uvs;
    vector<vec3> norms;
    objLoader.LoadObject("models/test_cube.obj", verts, uvs, norms);
    cout << "norm size " << norms.size() << endl;
    cout << "verts size " << verts.size() << endl;
    cout << "uvs size " << uvs.size() << endl;
}