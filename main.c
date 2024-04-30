#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "matrix_struct.h"
#include "matrix_functions.h"
#include "complex_functions.h"
#include "int_functions.h"
#include "error_types.h"
#include "ui.h"
#include "tests.h"

int error_code = 0;

int main()
{
    test_int_func();
    test_complex_func();

    field_info* int_field_info = create_int_info();
    field_info* complex_field_info = create_complex_info();

    if(NULL == int_field_info)
        error_set(LOW_MEMORY, &error_code);

    if(NULL == complex_field_info)
        error_set(LOW_MEMORY, &error_code);

    int status = 0, flag = 1;

    start_menu();

    while(flag && error_code == 0 && scanf("%d", &status))
    {
        switch (status)
        {
            case 0:
            {
                flag = 0;
                printf("Program completed\n");
                break;
            }
            case 1:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                int* mat_1;
                enter_int_elements(&mat_1, rows_1, columns_1);

                int rows_2;
                int columns_2;
                matrix_number(&rows_2, &columns_2);

                int* mat_2;
                enter_int_elements(&mat_2, rows_2, columns_2);

                matrix_struct* m1 = matrix_create(int_field_info, rows_1, columns_1, mat_1);
                matrix_struct* m2 = matrix_create(int_field_info, rows_2, columns_2, mat_2);

                matrix_print(m1);
                matrix_print(m2);

                int* mat_3;
                enter_nul_int_matrix(&mat_3, rows_1, columns_1);

                matrix_struct* m3 = matrix_create(int_field_info, rows_1, columns_1, mat_3);

                matrix_sum(m3, m1, m2);

                printf("result:\n");
                matrix_print(m3);

                matrix_free(m1);
                matrix_free(m2);
                matrix_free(m3);
                break;
            }
            case 2:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                int* mat_1;
                enter_int_elements(&mat_1, rows_1, columns_1);

                int rows_2;
                int columns_2;
                matrix_number(&rows_2, &columns_2);

                int* mat_2;
                enter_int_elements(&mat_2, rows_2, columns_2);

                matrix_struct* m1 = matrix_create(int_field_info, rows_1, columns_1, mat_1);
                matrix_struct* m2 = matrix_create(int_field_info, rows_2, columns_2, mat_2);

                matrix_print(m1);
                matrix_print(m2);

                int* mat_3;
                enter_nul_int_matrix(&mat_3, rows_1, columns_2);

                matrix_struct* m3 = matrix_create(int_field_info, rows_1, columns_2, mat_3);

                matrix_multi(m3, m1, m2);

                printf("result:\n");
                matrix_print(m3);

                matrix_free(m1);
                matrix_free(m2);
                matrix_free(m3);
                break;
            }
            case 3:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                int* mat_1;
                enter_int_elements(&mat_1, rows_1, columns_1);

                matrix_struct* m1 = matrix_create(int_field_info, rows_1, columns_1, mat_1);

                matrix_print(m1);

                int* mat_2;
                enter_nul_int_matrix(&mat_2, columns_1, rows_1);

                matrix_struct* m2 = matrix_create(int_field_info, columns_1, rows_1, mat_2);

                matrix_transposition(m2, m1);

                printf("result:\n");
                matrix_print(m2);

                matrix_free(m1);
                matrix_free(m2);
                break;
            }
            case 4:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                complex_number* mat_1;
                enter_complex_elements(&mat_1, rows_1, columns_1);

                int rows_2;
                int columns_2;
                matrix_number(&rows_2, &columns_2);

                complex_number* mat_2;
                enter_complex_elements(&mat_2, rows_2, columns_2);

                matrix_struct* m1 = matrix_create(complex_field_info, rows_1, columns_1, mat_1);
                matrix_struct* m2 = matrix_create(complex_field_info, rows_2, columns_2, mat_2);

                matrix_print(m1);
                matrix_print(m2);

                complex_number* mat_3;
                enter_nul_complex_matrix(&mat_3, rows_1, columns_1);

                matrix_struct* m3 = matrix_create(complex_field_info, rows_1, columns_1, mat_3);

                matrix_sum(m3, m1, m2);

                printf("result:\n");
                matrix_print(m3);

                matrix_free(m1);
                matrix_free(m2);
                matrix_free(m3);
                break;
            }
            case 5:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                complex_number* mat_1;
                enter_complex_elements(&mat_1, rows_1, columns_1);

                int rows_2;
                int columns_2;
                matrix_number(&rows_2, &columns_2);

                complex_number* mat_2;
                enter_complex_elements(&mat_2, rows_2, columns_2);

                matrix_struct* m1 = matrix_create(complex_field_info, rows_1, columns_1, mat_1);
                matrix_struct* m2 = matrix_create(complex_field_info, rows_2, columns_2, mat_2);

                matrix_print(m1);
                matrix_print(m2);

                complex_number* mat_3;
                enter_nul_complex_matrix(&mat_3, rows_1, columns_2);

                matrix_struct* m3 = matrix_create(complex_field_info, rows_1, columns_2, mat_3);

                matrix_multi(m3, m1, m2);

                printf("result:\n");
                matrix_print(m3);

                matrix_free(m1);
                matrix_free(m2);
                matrix_free(m3);
                break;
            }
            case 6:
            {
                int rows_1;
                int columns_1;
                matrix_number(&rows_1, &columns_1);

                complex_number* mat_1;
                enter_complex_elements(&mat_1, rows_1, columns_1);

                matrix_struct* m1 = matrix_create(complex_field_info, rows_1, columns_1, mat_1);

                matrix_print(m1);

                complex_number* mat_2;
                enter_nul_complex_matrix(&mat_2, columns_1, rows_1);

                matrix_struct* m2 = matrix_create(complex_field_info, columns_1, rows_1, mat_2);

                matrix_transposition(m2, m1);

                printf("result:\n");
                matrix_print(m2);

                matrix_free(m1);
                matrix_free(m2);
                break;
            }
            default:
            {
                fprintf(stderr, "Unknown command\n");
                break;
            }
        }
        if (status != 0)
        {
            start_menu();
        }

    }

    free(int_field_info);
    free(complex_field_info);

    return 0;
}