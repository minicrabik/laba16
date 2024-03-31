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


