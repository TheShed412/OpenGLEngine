#include <stdio.h>
#include <stdlib.h>
#include <chrono> 
#include <iostream> 

#include "headers/MatrixUtils.hpp"

using namespace std;
using namespace std::chrono;

/*
    It seems like the runtime is the same between these. HOWEVER this will be kept in
    mind if performance issues creep up, though only as a last resort. Since it seems like
    mat4 containing vec4 pointers doesn't increase the run time. Though I could just need
    better tests.
*/
// mat4* test_method_mat4(mat4* matrix) 
// {
//     matrix->col1.w = 1;
//     matrix->col1.x = 1;
//     matrix->col1.y = 1;
//     matrix->col1.z = 1;
//     return matrix;
// }

// mat4_vecptr* test_method_mat4_vecptr(mat4_vecptr* matrix) 
// {
//     matrix->col1->w = 1;
//     matrix->col1->x = 1;
//     matrix->col1->y = 1;
//     matrix->col1->z = 1;
//     return matrix;
// }

int main(int argc, char **argv)
{
    vec4 thing1 = {1, 2, 3, 4};
    vec4 thing2 = {1, 1, 1, 1};
    vec4* does_it_zero = new vec4;

    vec4* result = VecAdd(&thing1, &thing2);
    GLfloat result2 = VecMult(&thing1, &thing2);
    
    printf("x: %f\n", result->x);
    printf("y: %f\n", result->y);
    printf("z: %f\n", result->z);
    printf("w: %f\n", result->w);

    printf("mult: %f\n", result2);

    printf("x zero: %f\n", does_it_zero->x);
    printf("y zero: %f\n", does_it_zero->y);
    printf("z zero: %f\n", does_it_zero->z);
    printf("w zero: %f\n", does_it_zero->w);
}