#include <stdio.h>
#include <stdlib.h>

#include "complex_functions.h"

void complex_sum(void* res, void* num_1, void* num_2)
{
    ((complex_number* )res)->Re = ((complex_number* )num_1)->Re + ((complex_number* )num_2)->Re;
    ((complex_number* )res)->Im = ((complex_number* )num_1)->Im + ((complex_number* )num_2)->Im;
}

void complex_multi(void* res, void* num_1, void* num_2)
{
    ((complex_number* )res)->Re += ((complex_number* )num_1)->Re * ((complex_number* )num_2)->Re 
                                    - ((complex_number*)num_1)->Im * ((complex_number* )num_2)->Im;

    ((complex_number* )res)->Im += ((complex_number* )num_1)->Re * ((complex_number* )num_2)->Im 
                                    + ((complex_number*)num_1)->Im * ((complex_number* )num_2)->Re;
}

void complex_print(void* num)
{
    printf("%3d + %3di ", ((complex_number* )num)->Re, ((complex_number* )num)->Im);
}

field_info* create_complex_info()
{
    field_info* complex_info = (field_info* )malloc(sizeof(field_info));

    if(NULL == complex_info)
    {
        return NULL;
    }

    complex_info->elem_size = sizeof(complex_number);
    complex_info->elem_sum = &complex_sum;
    complex_info->elem_multi = &complex_multi;
    complex_info->elem_print = &complex_print;

    return complex_info;
}