#ifndef MAT_LIB
#define MAT_LIB

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define VEC_SIZE 4
#define MAT_SIZE VEC_SIZE * VEC_SIZE
#define NESTED_LOOP (VEC_SIZE*i) + j
#define INVERT_NESTED_LOOP (VEC_SIZE*j) + i

#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2


//TODO make all of these calsses with nifty constructors
typedef struct vec4
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
} vec4;

typedef struct vec3
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} vec3;

typedef struct vec2
{
    GLfloat x;
    GLfloat y;
} vec2;

typedef struct mat4
{
    vec4 col1;
    vec4 col2;
    vec4 col3;
    vec4 col4;

    public:
    mat4() {
        col1 = {1, 0, 0, 0};
        col2 = {0, 1, 0, 0};
        col3 = {0, 0, 1, 0};
        col4 = {0, 0, 0, 1};
    }
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
mat4* InvertMat(const mat4* matrix);
mat4* MatMult(const mat4* left, const mat4* right);

#endif