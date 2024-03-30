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

void test() {
    test_swap_min_max_rows();
}

int main() {
    test();

    return 0;
}
