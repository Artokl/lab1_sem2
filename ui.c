#include <stdio.h>
#include <stdlib.h>

#include "ui.h"
#include "error_types.h"
#include "complex_number.h"

extern int error_code;

void start_menu()
{
    printf("0. stop the program\n");
    printf("1. the sum of int_matrices\n");
    printf("2. the multiplication of int_matrices\n");
    printf("3. the transposition of int_matrices\n");
    printf("4. the sum of complex_matrices\n");
    printf("5. the multiplication of complex_matrices\n");
    printf("6. the transposition of complex_matrices\n");
}

void matrix_number(int* rows, int* columns)
{
    printf("enter the number of  the rows:\n");
    scanf("%d", rows);
    printf("enter the number of the columns:\n");
    scanf("%d", columns);
}

void enter_int_elements(int** mat, int rows, int columns)
{
    *(mat) = (int* )malloc((rows * columns) * sizeof(int));

    if(NULL == *(mat))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    printf("enter elements:\n");

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            scanf("%d", (*(mat) + i * columns + j));
        }
    }

}

void enter_nul_int_matrix(int** mat, int rows, int columns)
{
    *(mat) = (int* )malloc((rows * columns) * sizeof(int));

    if(NULL == *(mat))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            *(*(mat) + i * columns + j) = 0;
        }
    }
}

void enter_complex_elements(complex_number** mat, int rows, int columns)
{
    *(mat) = (complex_number* )malloc((rows * columns) * sizeof(complex_number));

    if(NULL == *(mat))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    printf("enter elements in the form of: Re Im\n");

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            scanf("%d", &((*(mat) + i * columns + j)->Re));
            scanf("%d", &((*(mat) + i * columns + j)->Im));
        }
    }
}

void enter_nul_complex_matrix(complex_number** mat, int rows, int columns)
{
    *(mat) = (complex_number* )malloc((rows * columns) * sizeof(complex_number));

    if(NULL == *(mat))
    {
        error_set(LOW_MEMORY, &error_code);
    }

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            ((*(mat) + i * columns + j)->Re) = 0;
            ((*(mat) + i * columns + j)->Im) = 0;
        }
    }
}