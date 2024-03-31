#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

//1 задание
void swapMinMaxRows(matrix* m){
    position mx = getMaxValuePos(*m);
    position mn = getMinValuePos(*m);

    swapRows(m, mx.row_index, mn.row_index);
}

//2 задание
int getMax(const int a[], const int n){
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (i > max)
            max = a[i];

    return max;
}

void sortRowsByMaxElement(matrix* m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

//3 задание
int getMin(const int a[], const int n){
    int min = a[0];

    for (int i = 1; i < n; i++)
        if (i < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix* m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

//4 задание
matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.n_cols != m2.n_rows) {
        fprintf(stderr, "Different dimensions of the matrices");
        exit(1);
    }

    matrix res = getMemMatrix(m1.n_rows, m2.n_rows);
    for (int i = 0; i < m1.n_rows; i++)
        for (int j = 0; j < m2.n_cols; j++) {
            res.values[i][j] = 0;
            for (int k = 0; k < m1.n_cols; k++)
                res.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return res;
}

void getSquareOfMatrixIfSymmetric(matrix* m) {
    if (!isSymmetricMatrix(m))
        return;

    matrix res = mulMatrices(*m, *m);

    freeMemMatrix(m);

    m->values = res.values;
    m->n_rows = res.n_rows;
    m->n_cols = res.n_cols;
}

// 5 задание
bool isUnique(long long int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}


long long int getSum(int a[], int n) {
    long long int res = 0;

    for (int i = 0; i < n; i++)
        res += a[i];

    return res;
}


void transposeIfMatrixHasNotEqualSumOfRows(matrix* m) {
    long long int sum[m->n_rows];

    for (int i = 0; i < m->n_rows; i++)
        sum[i] = getSum(m->values[i], m->n_cols);

    if (isUnique(sum, m->n_rows))
        transposeSquareMatrix(m);
}

//6 задание
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix multi = mulMatrices(m1, m2);

    bool is_e_matrix = isEMatrix(&multi);

    freeMemMmatrix(&multi);

    return is_e_matrix;
}

//7 задание
int max(int a, int b) {
    return (a > b) ? a : b;
}

long long int findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.n_rows;
    int k = m.n_cols;
    int* max_value = (int*) malloc(sizeof(int) * (n + k - 1));

    for (int i = 0; i < n + k - 1; i++)
        max_value[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            if (i != j)
                max_value[i - j + k - 1] = max(max_value[i - j + k - 1], m.values[i][j]);

    long long int sum = 0;
    for (int i = 0; i < n + k - 1; i++)
        sum += max_value[i];

    free(max_value);

    return sum;
}

// 8 задание
bool value_in_area(position max, int i, int j) {
    position new_position = {i - max.row_index, j - max.col_index};

    return (new_position.row_index <= new_position.col_index) && (new_position.row_index <= -new_position.col_index);
}


int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);

    int min = (int) 1e18;

    for (int i = 0; i <= max.row_index; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (value_in_area(max, i, j) && m.values[i][j] < min)
                min = m.values[i][j];

    return min;
}

//9 задание
float getDistance(int a[], int n) {
    long long int square_sum = 0;

    for (int i = 0; i < n; i++)
        square_sum += a[i] * a[i];

    return sqrt(square_sum);
}


void insertionSortRowsMatrixByRowCriteriaF(matrix* m, float (*criteria)(int*, int)) {
    float res_criteria[m->n_rows];

    for (size_t i = 0; i < m->n_rows; i++)
        res_criteria[i] = criteria(m->values[i], m->n_cols);

    int i, j;
    float key;
    int* address_key;
    for (i = 1; i < m->n_rows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}


void sortByDistance(matrix* m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// 10 задание


