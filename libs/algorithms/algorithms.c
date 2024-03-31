#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

void insertionSortColsMatrixByColCriteria(matrix *pMatrix, int (*min)(const int *, const int));

void swapMinMaxRows(matrix* m){
    position mx = getMaxValuePos(*m);
    position mn = getMinValuePos(*m);

    swapRows(m, mx.row_index, mn.row_index);
}

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




