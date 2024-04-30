#include <stdlib.h>
#include <assert.h>

#include "complex_functions.h"
#include "complex_number.h"
#include "field_info.h"
#include "int_functions.h"
#include "matrix_functions.h"
#include "matrix_struct.h"
#include "tests.h"

void test_int_sum()
{
    int a = 254;
    int b = -5;
    int ans_1 = a + b;
    int ans_2 = 0;
    int_sum((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1 == ans_2);
}

void test_int_multi()
{
    int a = 38;
    int b = -24;
    int ans_1 = b * a;
    int ans_2 = 0;
    int_multi((void*)&ans_2, (void*)&a, (void*)&b);
    assert(ans_1 == ans_2);
}

void test_int_transposition()
{
    field_info* int_field_info = create_int_info();

    int elem_1[] = {1, 25, 3, 32, 14, 18};
    int elem_2[] = {0, 0, 0, 0, 0, 0};

    matrix_struct* Mat_1 = matrix_create(int_field_info, 2, 3, elem_1);
    matrix_struct* Mat_2 = matrix_create(int_field_info, 3, 2, elem_2);

    matrix_transposition(Mat_2, Mat_1);

    assert(*((int* )Mat_2->elements) == elem_1[0]);
    assert(*((int* )Mat_2->elements + 1) == elem_1[3]);
    assert(*((int* )Mat_2->elements + 2) == elem_1[1]);
    assert(*((int* )Mat_2->elements + 3) == elem_1[4]);
    assert(*((int* )Mat_2->elements + 4) == elem_1[2]);
    assert(*((int* )Mat_2->elements + 5) == elem_1[5]);

    matrix_free_test(Mat_1);
    matrix_free_test(Mat_2);
    free(int_field_info);
}

void test_int_matrix_sum()
{
    field_info* int_field_info = create_int_info();

    int elem_1[] = {13, 5, 23, 3, 54, -5};
    int elem_2[] = {7, 34, 1, 43, 2, 1};
    int elem_3[] = {0, 0, 0, 0, 0, 0};

    matrix_struct* Mat_1 = matrix_create(int_field_info, 2, 3, elem_1);
    matrix_struct* Mat_2 = matrix_create(int_field_info, 2, 3, elem_2);
    matrix_struct* res = matrix_create(int_field_info, 2, 3, elem_3);

    matrix_sum(res, Mat_1, Mat_2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(*((int *)(res->elements) + i * 3 + j) == (elem_1[i * 3 + j] + elem_2[i * 3 + j]));
        }
    }

    matrix_free_test(Mat_1);
    matrix_free_test(Mat_2);
    matrix_free_test(res);
    free(int_field_info);
}

void test_int_matrix_multi()
{
    field_info* int_field_info = create_int_info();

    int elem_1[] = {1, 3476, 45, -6};
    int elem_2[] = {22, 0, 7645, 38};
    int elem_3[] = {0, 0, 0, 0};

    matrix_struct* Mat_1 = matrix_create(int_field_info, 2, 2, elem_1);
    matrix_struct* Mat_2 = matrix_create(int_field_info, 2, 2, elem_2);
    matrix_struct* res = matrix_create(int_field_info, 2, 2, elem_3); 

    matrix_multi(res, Mat_1, Mat_2);

    assert(*((int* )res->elements) == (elem_1[0] * elem_2[0] + elem_1[1] * elem_2[2]));
    assert(*((int* )res->elements + 1) == (elem_1[0] * elem_2[1] + elem_1[1] * elem_2[3]));
    assert(*((int* )res->elements + 2) == (elem_1[2] * elem_2[0] + elem_1[3] * elem_2[2]));
    assert(*((int* )res->elements + 3) == (elem_1[2] * elem_2[1] + elem_1[3] * elem_2[3]));

    matrix_free_test(Mat_1);
    matrix_free_test(Mat_2);
    matrix_free_test(res);
    free(int_field_info);
}

void test_int_func()
{
    test_int_sum();
    test_int_multi();
    test_int_matrix_sum();
    test_int_matrix_multi();
    test_int_transposition();
}

void test_complex_sum()
{
    complex_number a = {7, 2};
    complex_number b = {1, -8};

    complex_number ans_1 = {a.Re + b.Re, a.Im + b.Im};
    complex_number ans_2;

    complex_sum((void* )&ans_2, (void* )&a, (void* )&b);
    assert(ans_1.Re == ans_2.Re);
    assert(ans_1.Im == ans_2.Im);
}

void test_complex_multi()
{
    complex_number a = {26, -5};
    complex_number b = {5, 76};

    complex_number ans_1 = {a.Re * b.Re - a.Im * b.Im, a.Re * b.Im + a.Im * b.Re};
    complex_number ans_2 = {0, 0};

    complex_multi((void* )&ans_2, (void* )&a, (void* )&b);
    assert(ans_1.Re == ans_2.Re);
    assert(ans_1.Im == ans_2.Im);
}

void test_complex_transposition()
{
    field_info* complex_field_info = create_complex_info();

    complex_number elem_1[] = {{2, 9}, {1, 3}, {0, 13}, {-3, 47},
                      {87, 5}, {-78, 4}};
    complex_number elem_2[] = {{0, 0}, {0, 0}, {0, 0}, {0, 0},
                      {0, 0}, {0, 0}};

    matrix_struct* Mat = matrix_create(complex_field_info, 3, 2, elem_1);
    matrix_struct* res = matrix_create(complex_field_info, 2, 3, elem_2);

    matrix_transposition(res, Mat);

    assert(((complex_number* )res->elements)->Re == elem_1[0].Re);
    assert(((complex_number* )res->elements)->Im == elem_1[0].Im);
    assert(((complex_number* )res->elements + 1)->Re == elem_1[2].Re);
    assert(((complex_number* )res->elements + 1)->Im == elem_1[2].Im);
    assert(((complex_number* )res->elements + 2)->Re == elem_1[4].Re);
    assert(((complex_number* )res->elements + 2)->Im == elem_1[4].Im);
    assert(((complex_number* )res->elements + 3)->Re == elem_1[1].Re);
    assert(((complex_number* )res->elements + 3)->Im == elem_1[1].Im);
    assert(((complex_number* )res->elements + 4)->Re == elem_1[3].Re);
    assert(((complex_number* )res->elements + 4)->Im == elem_1[3].Im);
    assert(((complex_number* )res->elements + 5)->Re == elem_1[5].Re);
    assert(((complex_number* )res->elements + 5)->Im == elem_1[5].Im);

    matrix_free_test(Mat);
    matrix_free_test(res);
    free(complex_field_info);
}

void test_complex_matrix_sum()
{
    field_info* complex_field_info = create_complex_info();

    complex_number elem_1[] = {{32, -21}, {5, 456}, {32, 543}, {46, 98}, {82, 1}, {43, 19}};
    complex_number elem_2[] = {{11, 11}, {14, 212}, {0, 251}, {48, 56}, {76, -56}, {-97, 2}};
    complex_number elem_3[] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

    matrix_struct* Mat_1 = matrix_create(complex_field_info, 2, 3, elem_1);
    matrix_struct* Mat_2 = matrix_create(complex_field_info, 2, 3, elem_2);
    matrix_struct* res = matrix_create(complex_field_info, 2, 3, elem_3);
    
    matrix_sum(res, Mat_1, Mat_2);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(((complex_number* )res->elements + i * 3 + j)->Re == (elem_1[i * 3 + j].Re + elem_2[i * 3 + j].Re));
            assert(((complex_number* )res->elements + i * 3 + j)->Im == (elem_1[i * 3 + j].Im + elem_2[i * 3 + j].Im));
        }
    }

    matrix_free_test(Mat_1);
    matrix_free_test(Mat_2);
    matrix_free_test(res);
    free(complex_field_info);
}

void test_complex_matrix_multi()
{
    field_info* complex_field_info = create_complex_info();

    complex_number elem_1[] = {{1, 4}, {42, 24}, {131, 0}, {765, 61}};
    complex_number elem_2[] = {{76, 22}, {0, 7}, {34, 1}, {381, 8}};
    complex_number elem_3[] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

    matrix_struct* Mat_1 = matrix_create(complex_field_info, 2, 2, elem_1);
    matrix_struct* Mat_2 = matrix_create(complex_field_info, 2, 2, elem_2);
    matrix_struct* res = matrix_create(complex_field_info, 2, 2, elem_3);

    matrix_multi(res, Mat_1, Mat_2);

    complex_number ans_1 = {0, 0}, ans_2 = {0, 0};
    
    complex_multi((void* )&ans_1, (void* )&elem_1[0], (void* )&elem_2[0]);
    complex_multi((void* )&ans_2, (void* )&elem_1[1], (void* )&elem_2[2]);

    assert(((complex_number *)res->elements)->Re == (ans_1.Re + ans_2.Re));
    assert(((complex_number *)res->elements)->Im == (ans_1.Im + ans_2.Im));
    ans_1.Re = 0;
    ans_2.Re = 0;
    ans_1.Im = 0;
    ans_2.Im = 0;
    complex_multi((void* )&ans_1, (void* )&elem_1[0], (void* )&elem_2[1]);
    complex_multi((void* )&ans_2, (void* )&elem_1[1], (void* )&elem_2[3]);

    assert(((complex_number *)res->elements + 1)->Re == (ans_1.Re + ans_2.Re));
    assert(((complex_number *)res->elements + 1)->Im == (ans_1.Im + ans_2.Im));
    ans_1.Re = 0;
    ans_2.Re = 0;
    ans_1.Im = 0;
    ans_2.Im = 0;
    complex_multi((void* )&ans_1, (void* )&elem_1[2], (void* )&elem_2[0]);
    complex_multi((void* )&ans_2, (void* )&elem_1[3], (void* )&elem_2[2]);

    assert(((complex_number *)res->elements + 2)->Re == (ans_1.Re + ans_2.Re));
    assert(((complex_number *)res->elements + 2)->Im == (ans_1.Im + ans_2.Im));
    ans_1.Re = 0;
    ans_2.Re = 0;
    ans_1.Im = 0;
    ans_2.Im = 0;
    complex_multi((void* )&ans_1, (void* )&elem_1[2], (void* )&elem_2[1]);
    complex_multi((void* )&ans_2, (void* )&elem_1[3], (void* )&elem_2[3]);

    assert(((complex_number *)res->elements + 3)->Re == (ans_1.Re + ans_2.Re));
    assert(((complex_number *)res->elements + 3)->Im == (ans_1.Im + ans_2.Im));

    matrix_free_test(Mat_1);
    matrix_free_test(Mat_2);
    matrix_free_test(res);
    free(complex_field_info);
}

void test_complex_func()
{
    test_complex_sum();
    test_complex_multi();
    test_complex_matrix_sum();
    test_complex_matrix_multi();
    test_complex_transposition();
}