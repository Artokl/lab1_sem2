#ifndef COMPLEX_FUNCTIONS_H
#define COMPLEX_FUNCTIONS_H

#include "complex_number.h"
#include "field_info.h"

void complex_sum(void* res, void* num_1, void* num_2);

void complex_multi(void* res, void* num_1, void* num_2);

void complex_print(void* num);

field_info* create_complex_info();

#endif