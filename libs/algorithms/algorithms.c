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

    freeMemMatrix(&multi);

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
int cmpLongLong(const void* pa, const void* pb) {
    return (int)(*(long long int*) pa - *(long long int*) pb);
}


int countNUnique(long long int a[], int n) {
    int amount = 1;

    int i = 0;
    while (i < n - 1) {
        if (a[i] != a[i + 1])
            amount++;

        i++;
    }

    return amount;
}


int countEqClassesByRowsSum(matrix m) {
    long long int values[m.n_rows];

    for (int i = 0; i < m.n_rows; i++)
        values[i] = getSum(m.values[i], m.n_cols);

    qsort(values, m.n_rows, sizeof(long long int), cmpLongLong);

    int result = countNUnique(values, m.n_rows);

    return result;
}

//11 задание
int getNSpecialElement(matrix m) {
    int amount = 0;

    for (int i = 0; i < m.n_cols; i++) {
        int sum = m.values[0][i];
        int max_values = m.values[0][i];

        for (int j = 1; j < m.n_rows; j++) {
            sum += m.values[j][i];

            if (m.values[j][i] > max_values)
                max_values = m.values[j][i];
        }

        if (max_values > (sum - max_values))
            amount++;
    }

    return amount;
}

//12 задание
position getLeftMin(matrix m) {
    transposeSquareMatrix(&m);

    position min = getMinValuePos(m);

    return min;
}


void swapPenultimateRow(matrix* m, int n) {
    if (m->n_rows < 2)
        return;

    int* temp = (int*) malloc(sizeof(int) * m->n_rows);
    for (int i = 0; i < m->n_rows; i++)
        temp[i] = m->values[i][n];

    for (int i = 0; i < m->n_cols; i++)
        m->values[m->n_rows - 2][i] = temp[i];

    free(temp);
}

//13 задание
bool is_non_descending_sorted(const int a[], int n) {
    int i = 0;
    while (i < n - 1) {
        if (a[i] > a[i + 1])
            return false;
        i++;
    }
    return true;
}


bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.n_rows; i++)
        if (!is_non_descending_sorted(m.values[i], m.n_cols))
            return false;
    return true;
}


int countNonDescendingRowsMatrices(matrix ms[], int n_matrix) {
    int amount = 0;

    for (int i = 0; i < n_matrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            amount++;

    return amount;
}

//14 задание
int countValues(const int a[], int n, int value) {
    int amount = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == value)
            amount++;

    return amount;
}

int countZeroRows(matrix m) {
    int amount = 0;

    for (int i = 0; i < m.n_rows; i++) {
        int amount_zero = countValues(m.values[i], m.n_cols, 0);
        if (amount_zero == m.n_cols)
            amount++;
    }

    return amount;
}


void printMatrixWithMaxZeroRows(matrix ms[], int n_matrix) {
    int amount_zero[n_matrix];
    int max_zero_rows = 0;

    for (int i = 0; i < n_matrix; i++) {
        int amount_zero_rows = countZeroRows(ms[i]);
        amount_zero[i] = amount_zero_rows;

        if (amount_zero_rows > max_zero_rows)
            max_zero_rows = amount_zero_rows;
    }

    for (int i = 0; i < n_matrix; i++)
        if (amount_zero[i] == max_zero_rows)
            outputMatrix(ms + i);
}

