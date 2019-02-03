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

// GLfloat determinant(const mat4* matrix) {

//     /* values infront of the 3x3 determinants */
//     GLfloat val1 = matrix->col1.x;
//     GLfloat val2 = matrix->col1.y;
//     GLfloat val3 = matrix->col1.z;
//     GLfloat val4 = matrix->col1.w;

//     GLfloat matrix_array[4][4];
//     mat4_to_arr(matrix, matrix_array);

//     GLfloat** deter1_arr = deter3_from_array(matrix_array, X);
//     GLfloat** deter2_arr = deter3_from_array(matrix_array, Y);
//     GLfloat** deter3_arr = deter3_from_array(matrix_array, Z);
//     GLfloat** deter4_arr = deter3_from_array(matrix_array, W);

//     GLfloat deter1 = determinant3x3(deter1_arr);
//     GLfloat deter2 = determinant3x3(deter2_arr);
//     GLfloat deter3 = determinant3x3(deter3_arr);
//     GLfloat deter4 = determinant3x3(deter4_arr);

//     GLfloat deter;
//     deter = (val1*deter1) - (val2*deter2) + (val3*deter3) - (val4*deter4);

//     free_arr(&deter1_arr, 3);
//     free_arr(&deter2_arr, 3);
//     free_arr(&deter3_arr, 3);
//     free_arr(&deter4_arr, 3);
//     return deter;
// }