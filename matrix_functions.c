#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matrix_functions.h"
#include "error_types.h"

extern int error_code;

matrix_struct* matrix_create(field_info* elem_type, int rows, int columns, void* data)
{
    matrix_struct* matrix = (matrix_struct* )malloc(sizeof(matrix_struct));
    
    if(NULL == matrix)
    {
        return NULL;
    }

    matrix->rows = rows;
    matrix->columns = columns;
    matrix->elements_type = elem_type;
    size_t elem_size = elem_type->elem_size;
    matrix->elements = malloc(rows * columns * elem_size);

    if (matrix->elements == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            memcpy((char* )matrix->elements + i * columns * elem_size + j * elem_size, (char* )data + i * columns * elem_size + j * elem_size, elem_size);
        }
    }

    return matrix;
}

void matrix_free(matrix_struct* matrix)
{
    free(matrix->elements);
    matrix->rows = 0;
    matrix->columns = 0;
    matrix->elements_type = NULL;
    free(matrix);
}

void matrix_free_test(matrix_struct* matrix)
{
    free(matrix);
}

void matrix_sum(matrix_struct* res, matrix_struct* matrix_1, matrix_struct* matrix_2)
{
    if(matrix_1->rows == matrix_2->rows && matrix_1->columns == matrix_2->columns && matrix_1->elements_type == matrix_2->elements_type)
    {
        size_t elem_size = matrix_1->elements_type->elem_size;
        int rows = matrix_1->rows;
        int columns = matrix_1->columns;

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < columns; ++j)
            {
                matrix_1->elements_type->elem_sum((void* )((char* )res->elements + i * columns * elem_size + j * elem_size),
                     (void* )((char* )matrix_1->elements + i * columns * elem_size + j * elem_size),
                         (void* )((char* )matrix_2->elements + i * columns * elem_size + j * elem_size));
            }
        }
    }

    else if (matrix_1->rows != matrix_2->rows || matrix_1->columns != matrix_2->columns)
    {
        error_set(MATRICES_SIZE, &error_code);
    }
    else if (matrix_1->elements_type != matrix_2->elements_type)
    {
        error_set(ELEM_TYPE, &error_code);
    }
    
}

void matrix_multi(matrix_struct* res, const matrix_struct* matrix_1, const matrix_struct* matrix_2)
{
    if(matrix_1->columns == matrix_2->rows && matrix_1->elements_type == matrix_2->elements_type)
    {
        size_t elem_size = matrix_1->elements_type->elem_size;
        int rows = matrix_1->rows;
        int columns = matrix_2->columns;

        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < columns; ++j)
            {            
                for(int k = 0; k < matrix_2->rows; ++k)
                {
                    matrix_1->elements_type->elem_multi((void* )((char* )res->elements + i * rows * elem_size + j * elem_size),
                     (void* )((char* )matrix_1->elements + i * matrix_1->columns * elem_size + k * elem_size),
                         (void* )((char* )matrix_2->elements + k * columns * elem_size + j * elem_size));
                }
            }
        }
    }

    else if (matrix_1->columns != matrix_2->rows)
    {
        error_set(MATRICES_SIZE, &error_code);
    }
    else if (matrix_1->elements_type != matrix_2->elements_type)
    {
        error_set(ELEM_TYPE, &error_code);
    }
}

void matrix_transposition(matrix_struct* res, matrix_struct* matrix_1)
{
    int columns = matrix_1->rows;
    int rows = matrix_1->columns;
    size_t elem_size = matrix_1->elements_type->elem_size;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            void* trans_elem = (char* )matrix_1->elements + j * rows * elem_size + i * elem_size;
            setToMatrix(res, i, j, trans_elem);
        }
    }
}

void matrix_print(matrix_struct* matrix)
{
    size_t elem_size = matrix->elements_type->elem_size;
    int rows = matrix->rows;
    int columns = matrix->columns;

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            matrix->elements_type->elem_print((void* )((char* ) matrix->elements + i * columns * elem_size + j * elem_size));
        }
        putchar('\n');
    }
    putchar('\n');
}

void setToMatrix(matrix_struct* matrix_1, size_t i, size_t j, void* element)
{
    size_t elem_size = matrix_1->elements_type->elem_size;
    memcpy((char* )matrix_1->elements + i * matrix_1->columns * elem_size + j * elem_size, element, elem_size);
}