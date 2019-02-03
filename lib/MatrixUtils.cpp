#include "../headers/MatrixUtils.hpp"

#define X 0
#define Y 0
#define Z 0
#define W 0


vec4* vec_add(const vec4* left, const vec4* right)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for(int i = 0; i < VEC_SIZE; i++) {
        result[i] = left_dbl[i] + right_dbl[i]; 
    }

    return (vec4*)result;
}

GLfloat vec_mult(const vec4* left, const vec4* right)
{
    GLfloat result = 0;
    GLfloat* left_dbl = (GLfloat*) left;
    GLfloat* right_dbl = (GLfloat*) right;

    for(int i = 0; i < VEC_SIZE; i++) {
        result += left_dbl[i] * right_dbl[i]; 
    }

    return result;
}

vec4* vec_cross(const vec4* left, const vec4* right)
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
