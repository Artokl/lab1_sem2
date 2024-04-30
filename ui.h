#ifndef UI_H
#define UI_H

#include"complex_number.h"

void start_menu();

void matrix_number(int* rows, int* columns);

void enter_int_elements(int** mat, int rows, int columns);

void enter_nul_int_matrix(int** mat, int rows, int columns);

void enter_complex_elements(complex_number** mat, int rows, int columns);

void enter_nul_complex_matrix(complex_number** mat, int rows, int columns);

#endif