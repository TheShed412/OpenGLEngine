#include "../headers/MatrixUtils.hpp"
//TODO return normal mats in all of the functions
#define X 0
#define Y 0
#define Z 0
#define W 0

vec4 origin = {0, 0, 0, 0};

mat4* GetIdentityMatrix() {
    mat4* id = new mat4;

    return id;
}

//TODO use the rotation caculation in the arbitrary rotate instead
mat4 XRotate(GLfloat theta) 
{
    mat4 rotMat;

    GLfloat cosTheta = cos(theta);
    GLfloat sinTheta = sin(theta);

    rotMat.col2.y = cosTheta;
    rotMat.col3.y = sinTheta * -1;
    rotMat.col2.z = sinTheta;
    rotMat.col3.z = cosTheta;

    return rotMat;
}

mat4 YRotate(GLfloat theta) 
{
    mat4 rotMat;

    GLfloat cosTheta = cos(theta);
    GLfloat sinTheta = sin(theta);

    rotMat.col1.x = cosTheta;
    rotMat.col1.z = sinTheta * -1;
    rotMat.col3.x = sinTheta;
    rotMat.col3.z = cosTheta;

    return rotMat;
}

mat4 ZRotate(GLfloat theta) 
{
    mat4 rotMat;

    GLfloat cosTheta = cos(theta);
    GLfloat sinTheta = sin(theta);

    rotMat.col1.x = cosTheta;
    rotMat.col2.x = sinTheta * -1;
    rotMat.col1.y = sinTheta;
    rotMat.col2.y = cosTheta;

    return rotMat;
}

mat4 GetRotationMatrix(GLfloat theta, int axis) 
{
    mat4 rotMat;

    switch(axis) {
        case X_AXIS:
            rotMat = XRotate(theta);
        break;

        case Y_AXIS:
            rotMat = YRotate(theta);
        break;

        case Z_AXIS:
            rotMat = ZRotate(theta);
        break;
    }

    return rotMat;
}

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

GLfloat VecMag(const vec4* vec) 
{
    return sqrt(vec->x*vec->x + vec->y*vec->y + vec->z*vec->z);
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

static vec4* vec_from_row(const GLfloat* matrix, int row){
    GLfloat* result = new GLfloat[VEC_SIZE];

    /* looping across the columns to get the rows */
    for(int i = 0; i < VEC_SIZE; i ++) {
        result[i] = matrix[(VEC_SIZE*row) + i];
    }

    return (vec4*)result;
}

static vec4* vec_from_col(const GLfloat* matrix, int row){
    GLfloat* result = new GLfloat[VEC_SIZE];

    /* looping across the columns to get the rows */
    for(int i = 0; i < VEC_SIZE; i ++) {
        result[i] = matrix[(VEC_SIZE*i) + row];
    }

    return (vec4*)result;
}


mat4* MatMult(const mat4* left, const mat4* right)
{
    vec4 row_vec; // vec from the left_op
    vec4 col_vec; // vec from the right_op
    GLfloat* result = new GLfloat[MAT_SIZE];
    GLfloat* left_op = (GLfloat*) left;
    GLfloat* right_op = (GLfloat*) right;

    /* loop is iterating through the rows */
    for(int row_i = 0; row_i < VEC_SIZE; row_i++) {
        row_vec = (*vec_from_row(left_op, row_i));

        for(int col_j = 0; col_j < VEC_SIZE; col_j++) {
            col_vec = (*vec_from_col(right_op, col_j));
            GLfloat point = VecMult(&row_vec, &col_vec);
            result[(VEC_SIZE*row_i) + col_j] = point;
        }
    }

    return (mat4*)result;
}

/* based on implementation from mesa */
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

/* this might only work for objects with center at origin...maybe i dunno. not like i wrote it. oh wait. */
mat4* ArbitrayRotate(GLfloat zTheta, const vec4* axis) {
    GLfloat sizeOfAxis = sqrt(axis->x*axis->x + axis->z*axis->z + axis->y*axis->y);
    vec4* atOrigin = ScalarMultVec(axis, 1/sizeOfAxis);

    GLfloat vx = atOrigin->x;
    GLfloat vy = atOrigin->y;
    GLfloat vz = atOrigin->z;
    GLfloat d = sqrt(vy*vy + vz*vz);

    // mat4 rotToYZPlane = {
    //     1,     0,    0, 0,
    //     0,  vz/d, vy/d, 0,
    //     0, -vy/d, vz/d, 0,
    //     0,     0,    0, 1,
    // };
    mat4 rotToYZPlane;
    rotToYZPlane.col2.y = vz/d;
    rotToYZPlane.col2.z = -vz/d;
    rotToYZPlane.col3.y = vz/d;
    rotToYZPlane.col3.z = vz/d;

    vec4* atYZPlane = MatMultVec(&rotToYZPlane, atOrigin);

    GLfloat zAdj = sqrt(vz*vz + vx*vx);
    // mat4 rotToZ = {
    //     d,   0, vx, 0,
    //     0,   1, 0,  0,
    //     -vx, 0, d,  0,
    //     0,   0, 0,  1
    // };
    mat4 rotToZ;
    rotToZ.col1.x = d;
    rotToZ.col1.z = -vx;
    rotToZ.col3.x = vx;
    rotToZ.col3.z = d;

    mat4 rotAroundZ = GetRotationMatrix(-1 * zTheta, Z);

    mat4* doRotateMat = MatMult(&rotToZ, &rotToYZPlane);
    doRotateMat = MatMult(&rotAroundZ, doRotateMat);

    mat4* rotFromZ = InvertMat(&rotToZ);
    mat4* rotFromYZ = InvertMat(&rotToYZPlane);

    mat4* undoRotate = MatMult(rotFromYZ, rotFromZ);

    mat4* final_mat = MatMult(undoRotate, doRotateMat);

    delete rotFromZ;
    delete rotFromYZ;
    delete doRotateMat;
    delete undoRotate;
    delete atYZPlane;
    delete atOrigin;

    return final_mat;
}