#ifndef MATRIX_STRUCT_H
#define MATRIX_STRUCT_H

#include "field_info.h"

typedef struct matrix_struct
{
    int rows;
    int columns;
    void* elements;
    field_info* elements_type;
} matrix_struct;

#endif