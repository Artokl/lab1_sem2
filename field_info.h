#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct field_info
{
    size_t elem_size;
    
    void (*elem_sum)(void* res, void* num_1, void* num_2);
    void (*elem_multi)(void* res, void* num_1, void* num_2);
    void (*elem_print)(void* num);
} field_info;

#endif