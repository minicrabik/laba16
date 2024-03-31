#include <stdio.h>
#include <assert.h>
#include <memory.h>

#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithms.h"

void test_swap_min_max_rows_1_standard_swap(){
    matrix m = createMatrixFromArray((int []){1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);
    matrix check = createMatrixFromArray((int []){7, 8, 9,
                                                  4, 5, 6,
                                                  1, 2, 3}, 3,3);
    swapMinMaxRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_2_min_and_max_element_equal(){
    matrix m = createMatrixFromArray((int []){1, 1, 1,
                                              1, 1, 1,
                                              1, 1, 1}, 3, 3);
    matrix check = createMatrixFromArray((int []){1, 1, 1,
                                                  1, 1, 1,
                                                  1, 1, 1}, 3,3);
    swapMinMaxRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_3_min_and_max_element_in_one_row(){
    matrix m = createMatrixFromArray((int []){1, 9, 1,
                                              1, 1, 1,
                                              1, 1, 1}, 3, 3);
    matrix check = createMatrixFromArray((int []){1, 9, 1,
                                                  1, 1, 1,
                                                  1, 1, 1}, 3,3);
    swapMinMaxRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows() {
    test_swap_min_max_rows_1_standard_swap();
    test_swap_min_max_rows_2_min_and_max_element_equal();
    test_swap_min_max_rows_3_min_and_max_element_in_one_row();
}

void test_sort_rows_by_max_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                                 1, 8, 1,
                                                 3, 2, 3}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {3, 2, 3,
                                                     7, 1, 2,
                                                     1, 8, 1},3, 3);

    sortRowsByMaxElement(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element_2_max_value_equal() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 7, 1,
                                              3, 7, 7}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {7, 2, 3,
                                                  7, 1, 2,
                                                  3, 7, 7},3, 3);

    sortRowsByMaxElement(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element() {
    test_sort_rows_by_max_element_1_standard_value();
    test_sort_rows_by_max_element_2_max_value_equal();
}

void test_sort_cols_by_min_element_1_standart_value(){
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                 2, 5, 1, 8, 2, 7,
                                                 6, 1, 4, 4, 8, 3}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                     5, 1, 2, 2, 7, 8,
                                                     1, 4, 6, 8, 3, 4},3, 6);

    sortColsByMinElement(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element_2_min_value_equal() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 3,
                                                 1, 5, 1, 8, 1, 7,
                                                 6, 1, 4, 4, 8, 1}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {3, 5, 2, 1, 3, 3,
                                                     1, 5, 1, 8, 1, 7,
                                                     6, 1, 4, 4, 8, 1},3, 6);

    sortColsByMinElement(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element(){
    test_sort_cols_by_min_element_1_standart_value();
    test_sort_cols_by_min_element_2_min_value_equal();
}

void test() {
    test_swap_min_max_rows();
    test_sort_rows_by_max_element();
    test_sort_cols_by_min_element();
}

int main() {
    test();

    return 0;
}
