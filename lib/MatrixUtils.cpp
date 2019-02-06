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

mat4* TransposeMat(const mat4* matrix)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* matrix_dbl = (GLfloat*) matrix;

    for (int i = 0; i < VEC_SIZE; i++) {
        for (int j = 0; j < VEC_SIZE; j++) {
            result[(VEC_SIZE*i) + j] = matrix_dbl[(VEC_SIZE*j) + i];
        }
    }

    return (mat4*)result;
}

//// INVERSE STUFF CAUSE THAT'S HARD ////
static GLfloat determinant3x3(GLfloat** deter3) {

    GLfloat a11 = deter3[0][0];
    GLfloat a12 = deter3[0][1];
    GLfloat a13 = deter3[0][2];

    GLfloat a21 = deter3[1][0];
    GLfloat a22 = deter3[1][1];
    GLfloat a23 = deter3[1][2];

    GLfloat a31 = deter3[2][0];
    GLfloat a32 = deter3[2][1];
    GLfloat a33 = deter3[2][2];

    GLfloat positive = (a11*a22*a33) + (a12*a23*a31) + (a21*a32*a13);
    GLfloat negative = (a13*a22*a31) + (a21*a12*a33) + (a23*a32*a11);

    return positive - negative;
}

mat4* InvertMat(const mat4* matrix)
{
    GLfloat* result = new GLfloat[VEC_SIZE];
    GLfloat* m = (GLfloat*) matrix;
    double inv[16], det;
    int i;

    inv[0] = m[5]  * m[10] * m[15] - 
             m[5]  * m[11] * m[14] - 
             m[9]  * m[6]  * m[15] + 
             m[9]  * m[7]  * m[14] +
             m[13] * m[6]  * m[11] - 
             m[13] * m[7]  * m[10];

    inv[4] = -m[4]  * m[10] * m[15] + 
              m[4]  * m[11] * m[14] + 
              m[8]  * m[6]  * m[15] - 
              m[8]  * m[7]  * m[14] - 
              m[12] * m[6]  * m[11] + 
              m[12] * m[7]  * m[10];

    inv[8] = m[4]  * m[9] * m[15] - 
             m[4]  * m[11] * m[13] - 
             m[8]  * m[5] * m[15] + 
             m[8]  * m[7] * m[13] + 
             m[12] * m[5] * m[11] - 
             m[12] * m[7] * m[9];

    inv[12] = -m[4]  * m[9] * m[14] + 
               m[4]  * m[10] * m[13] +
               m[8]  * m[5] * m[14] - 
               m[8]  * m[6] * m[13] - 
               m[12] * m[5] * m[10] + 
               m[12] * m[6] * m[9];

    inv[1] = -m[1]  * m[10] * m[15] + 
              m[1]  * m[11] * m[14] + 
              m[9]  * m[2] * m[15] - 
              m[9]  * m[3] * m[14] - 
              m[13] * m[2] * m[11] + 
              m[13] * m[3] * m[10];

    inv[5] = m[0]  * m[10] * m[15] - 
             m[0]  * m[11] * m[14] - 
             m[8]  * m[2] * m[15] + 
             m[8]  * m[3] * m[14] + 
             m[12] * m[2] * m[11] - 
             m[12] * m[3] * m[10];

    inv[9] = -m[0]  * m[9] * m[15] + 
              m[0]  * m[11] * m[13] + 
              m[8]  * m[1] * m[15] - 
              m[8]  * m[3] * m[13] - 
              m[12] * m[1] * m[11] + 
              m[12] * m[3] * m[9];

    inv[13] = m[0]  * m[9] * m[14] - 
              m[0]  * m[10] * m[13] - 
              m[8]  * m[1] * m[14] + 
              m[8]  * m[2] * m[13] + 
              m[12] * m[1] * m[10] - 
              m[12] * m[2] * m[9];

    inv[2] = m[1]  * m[6] * m[15] - 
             m[1]  * m[7] * m[14] - 
             m[5]  * m[2] * m[15] + 
             m[5]  * m[3] * m[14] + 
             m[13] * m[2] * m[7] - 
             m[13] * m[3] * m[6];

    inv[6] = -m[0]  * m[6] * m[15] + 
              m[0]  * m[7] * m[14] + 
              m[4]  * m[2] * m[15] - 
              m[4]  * m[3] * m[14] - 
              m[12] * m[2] * m[7] + 
              m[12] * m[3] * m[6];

    inv[10] = m[0]  * m[5] * m[15] - 
              m[0]  * m[7] * m[13] - 
              m[4]  * m[1] * m[15] + 
              m[4]  * m[3] * m[13] + 
              m[12] * m[1] * m[7] - 
              m[12] * m[3] * m[5];

    inv[14] = -m[0]  * m[5] * m[14] + 
               m[0]  * m[6] * m[13] + 
               m[4]  * m[1] * m[14] - 
               m[4]  * m[2] * m[13] - 
               m[12] * m[1] * m[6] + 
               m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] + 
              m[1] * m[7] * m[10] + 
              m[5] * m[2] * m[11] - 
              m[5] * m[3] * m[10] - 
              m[9] * m[2] * m[7] + 
              m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] - 
             m[0] * m[7] * m[10] - 
             m[4] * m[2] * m[11] + 
             m[4] * m[3] * m[10] + 
             m[8] * m[2] * m[7] - 
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] + 
               m[0] * m[7] * m[9] + 
               m[4] * m[1] * m[11] - 
               m[4] * m[3] * m[9] - 
               m[8] * m[1] * m[7] + 
               m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] - 
              m[0] * m[6] * m[9] - 
              m[4] * m[1] * m[10] + 
              m[4] * m[2] * m[9] + 
              m[8] * m[1] * m[6] - 
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0)
        return nullptr;

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        result[i] = inv[i] * det;

    return (mat4*)result;
}