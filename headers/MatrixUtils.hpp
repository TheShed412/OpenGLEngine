#ifndef MAT_LIB
#define MAT_LIB

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE 4

typedef struct vec4
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
} vec4;

typedef struct mat4
{
    vec4 col1;
    vec4 col2;
    vec4 col3;
    vec4 col4;
} mat4;

vec4* vec_add(const vec4* left, const vec4* right);
GLfloat vec_mult(const vec4* left, const vec4* right);

#endif