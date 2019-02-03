#include <stdio.h>
#include <stdlib.h>

#include "headers/MatrixUtils.hpp"

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