#include "../headers/MatrixUtils.hpp"

#define X 0
#define Y 0
#define Z 0
#define W 0


vec4* VecAdd(const vec4* left, const vec4* right)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for(int i = 0; i < VEC_SIZE; i++) {
        result[i] = left_dbl[i] + right_dbl[i]; 
    }

    return (vec4*)result;
}

GLfloat VecMult(const vec4* left, const vec4* right)
{
    GLfloat result = 0;
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for(int i = 0; i < VEC_SIZE; i++) {
        result += left_dbl[i] * right_dbl[i]; 
    }

    return result;
}

vec4* VecCross(const vec4* left, const vec4* right)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;
    
    result[X] = (left_dbl[Y]*right_dbl[Z]) - (left_dbl[Z]*right_dbl[Y]);
    result[Y] = (left_dbl[Z]*right_dbl[X]) - (left_dbl[X]*right_dbl[Z]);
    result[Z] = (left_dbl[X]*right_dbl[Y]) - (left_dbl[Y]*right_dbl[X]);
    result[W] = 0;

    return (vec4*)result;
}

vec4* VecSub(const vec4* left, const vec4* right)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for(int i = 0; i < VEC_SIZE; i++) {
        result[i] = left_dbl[i] - right_dbl[i]; 
    }

    return (vec4*)result;
}

vec4* ScalarMultVec(const vec4* vector, GLfloat scalar)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* vector_dbl = (GLfloat*) vector;

    for (int i=0; i < VEC_SIZE; i++) {
        result[i] = vector_dbl[i] * scalar;
    }

    return (vec4*)result;
}

mat4* MatAdd(const mat4* left, const mat4* right)
{
    GLfloat* result = new GLfloat[MAT_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for (int i=0; i < MAT_SIZE; i++) {
        result[i] = left_dbl[i] + right_dbl[i];
    }

    return (mat4*)result;
}

mat4* MatSub(const mat4* left, const mat4* right)
{
    GLfloat* result = new GLfloat[MAT_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for (int i=0; i < MAT_SIZE; i++) {
        result[i] = left_dbl[i] - right_dbl[i];
    }

    return (mat4*)result;
}


vec4* MatMultVec(const mat4* matrix, const vec4* vector)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* matrix_dbl = (GLfloat*) matrix;
    GLfloat* vector_dbl = (GLfloat*) vector;

    for (int i=0; i < VEC_SIZE; i++) {
        GLfloat row_result = 0;
        for (int j=0; j < VEC_SIZE; j++) {
            row_result += matrix_dbl[(VEC_SIZE*i) + j] * vector_dbl[j];
        }
        result[i] = row_result;
    }

    return (vec4*)result;
}