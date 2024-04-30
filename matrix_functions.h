#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

#include "matrix_struct.h"


matrix_struct* matrix_create(field_info* elem_type, int rows, int columns, void* data);

void matrix_free(matrix_struct* matrix);

void matrix_free_test(matrix_struct* matrix);

void matrix_sum(matrix_struct* res, matrix_struct* matrix_1, matrix_struct* matrix_2);

void matrix_multi(matrix_struct* res, const matrix_struct* matrix_1, const matrix_struct* matrix_2);

void matrix_print(matrix_struct* matrix);

void matrix_transposition(matrix_struct* res, matrix_struct* matrix_1);

void setToMatrix(matrix_struct* matrix_1, size_t i, size_t j, void* element);
#endif