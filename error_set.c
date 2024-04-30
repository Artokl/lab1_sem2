#include <stdio.h>
#include <stdlib.h>

#include "error_types.h"


void error_set(int error_code, int* mat)
{
    switch(error_code)
    {
        case MATRICES_SIZE:
            *(mat) = MATRICES_SIZE;
            printf("The operation was not performed due to mismatch in the dimensions of the matrices\n");
            exit(1);
            break;

        case ELEM_TYPE:
            *(mat) = ELEM_TYPE;
            printf("The operationw was not performed due to a type mismatch\n");
            exit(1);
            break;

        case LOW_MEMORY:
            *(mat) = LOW_MEMORY;
            printf("The operation was not performed due to lack of memory\n");
            exit(1);
            break;

        default:
            break;
    }
}