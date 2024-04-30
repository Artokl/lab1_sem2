#ifndef INT_FUNCTIONS_H
#define INT_FUNCTIONS_H

#include "field_info.h"

void int_sum(void* res, void* num_1, void* num_2);

void int_multi(void* res, void* num_1, void* num_2);

void int_print(void* num);

field_info* create_int_info();

#endif