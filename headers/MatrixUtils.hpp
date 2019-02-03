#ifndef MAT_LIB
#define MAT_LIB

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include <stdlib.h>

#define VEC_SIZE 4
#define MAT_SIZE VEC_SIZE * VEC_SIZE

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

vec4* VecAdd(const vec4* left, const vec4* right);
GLfloat VecMult(const vec4* left, const vec4* right);
vec4* VecCross(const vec4* left, const vec4* right);
vec4* VecSub(const vec4* left, const vec4* right);
vec4* ScalarMultVec(const vec4* vector, GLfloat scalar);
vec4* MatMultVec(const mat4* matrix, const vec4* vector);
mat4* MatSub(const mat4* left, const mat4* right);
mat4* MatAdd(const mat4* left, const mat4* right);
vec4* ScalarMultVec(const vec4* vector, GLfloat scalar);
mat4* TransposeMat(const mat4* matrix);

#endif