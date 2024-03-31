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

void test_mul_matrices_1_standard_value() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {30, 36, 42,
                                                     66, 81, 96,
                                                     102, 126, 150}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mul_matrices_2_mul_to_e_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mul_matrices_3_mul_to_null_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 0, 0,
                                                  0, 0, 0,
                                                  0, 0, 0}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                     0, 0, 0,
                                                     0, 0, 0}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mul_matrices() {
    test_mul_matrices_1_standard_value();
    test_mul_matrices_2_mul_to_e_matrix();
    test_mul_matrices_3_mul_to_null_matrix();
}




void test_get_square_of_matrix_if_symmetric_1_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 2, 5, 6,
                                                 3, 6, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {14, 30, 42,
                                                     30, 65, 90,
                                                     42, 90, 126}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_get_square_of_matrix_if_symmetric_2_not_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                     4, 5, 6,
                                                     7, 8, 9}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_get_square_of_matrix_if_symmetric_3_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                                 0, 1, 0,
                                                 0, 0, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                     0, 1, 0,
                                                     0, 0, 1}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_get_square_of_matrix_if_symmetric() {
    test_get_square_of_matrix_if_symmetric_1_symmetric_matrix();
    test_get_square_of_matrix_if_symmetric_2_not_symmetric_matrix();
    test_get_square_of_matrix_if_symmetric_3_e_matrix();
}




void test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                     2, 5, 8,
                                                     3, 6, 9}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                                 4, 5, 6,
                                                 0, 3, 0}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                     4, 5, 6,
                                                     0, 3, 0}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_if_matrix_has_not_equal_sum_of_rows() {
    test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value();
    test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum();
}




void test_is_mutually_inverse_matrices_1_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                                  1, -2}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                                  1, -3}, 2, 2);

    bool result = isMutuallyInverseMatrices(m1, m2);

    assert(result == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_is_mutually_inverse_matrices_2_not_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, -5,
                                                  1, -2}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                                  1, -3}, 2, 2);

    bool result = isMutuallyInverseMatrices(m1, m2);

    assert(result == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}


void test_is_mutually_inverse_matrices() {
    test_is_mutually_inverse_matrices_1_inverse_matrices();
    test_is_mutually_inverse_matrices_2_not_inverse_matrices();
}




void test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                                 1, 3, 6, 3,
                                                 3, 2, 1, 2}, 3, 4);

    long long int result = findSumOfMaxesOfPseudoDiagonal(m);

    assert(result == 20);

    freeMemMatrix(&m);
}


void test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element() {
    matrix m = createMatrixFromArray((int[]) {3}, 1, 1);

    long long int result = findSumOfMaxesOfPseudoDiagonal(m);

    assert(result == 0);

    freeMemMatrix(&m);
}


void test_find_sum_of_maxes_of_pseudo_diagonal() {
    test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value();
    test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element();
}




void test_get_min_in_area_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                                 3, 11, 8, 9,
                                                 4, 1, 12, 2}, 3, 4);

    int result = getMinInArea(m);

    assert(result == 5);

    freeMemMatrix(&m);
}


void test_get_min_in_area_2_max_value_in_first_row() {
    matrix m = createMatrixFromArray((int[]) {10, 12, 5, 6,
                                                 3, 11, 8, 9,
                                                 4, 1, 7, 2}, 3, 4);

    int result = getMinInArea(m);

    assert(result == 12);

    freeMemMatrix(&m);
}


void test_get_min_in_area_3_equal_element() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                                 0, 0}, 2, 2);

    int result = getMinInArea(m);

    assert(result == 0);

    freeMemMatrix(&m);
}


void test_get_min_in_area() {
    test_get_min_in_area_1_standard_value();
    test_get_min_in_area_2_max_value_in_first_row();
    test_get_min_in_area_3_equal_element();
}




void test_sort_by_distance_1_different_distance() {
    matrix v = createMatrixFromArray((int[]) {2, 2, 2,
                                                 3, 3, 3,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                     2, 2, 2,
                                                     3, 3, 3}, 3, 3);

    sortByDistance(&v);

    assert(areTwoMatricesEqual(&v, &check));

    freeMemMatrix(&v);
    freeMemMatrix(&check);
}


void test_sort_by_distance_2_equal_distance() {
    matrix v = createMatrixFromArray((int[]) {1, 2, 3,
                                                 2, 1, 3,
                                                 3, 1, 2}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                     2, 1, 3,
                                                     3, 1, 2}, 3, 3);

    sortByDistance(&v);

    assert(areTwoMatricesEqual(&v, &check));

    freeMemMatrix(&v);
    freeMemMatrix(&check);
}


void test_sort_by_distance() {
    test_sort_by_distance_1_different_distance();
    test_sort_by_distance_2_equal_distance();
}

void test_count_eq_classes_by_rows_sum_1_different_sum() {
    matrix v = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9,
                                                 12, 1, 2}, 4, 3);


    int result = countEqClassesByRowsSum(v);

    assert(result == 3);

    freeMemMatrix(&v);
}


void test_count_eq_classes_by_rows_sum_2_all_sum_different() {
    matrix v = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9,
                                                 10, 11, 12}, 4, 3);


    int result = countEqClassesByRowsSum(v);

    assert(result == 4);

    freeMemMatrix(&v);
}


void test_count_eq_classes_by_rows_sum_3_equal_sum() {
    matrix v = createMatrixFromArray((int[]) {1, 2, 3,
                                                 1, 3, 2,
                                                 2, 1, 3,
                                                 2, 3, 1}, 4, 3);


    int result = countEqClassesByRowsSum(v);

    assert(result == 1);

    freeMemMatrix(&v);
}


void test_count_eq_classes_by_rows_sum() {
    test_count_eq_classes_by_rows_sum_1_different_sum();
    test_count_eq_classes_by_rows_sum_2_all_sum_different();
    test_count_eq_classes_by_rows_sum_3_equal_sum();
}



void test() {
    test_swap_min_max_rows();
    test_sort_rows_by_max_element();
    test_sort_cols_by_min_element();
    test_mul_matrices();
    test_get_square_of_matrix_if_symmetric();
    test_transpose_if_matrix_has_not_equal_sum_of_rows();
    test_is_mutually_inverse_matrices();
    test_find_sum_of_maxes_of_pseudo_diagonal();
    test_get_min_in_area();
    test_sort_by_distance();
    test_count_eq_classes_by_rows_sum();
}

int main() {
    test();

    return 0;
}
