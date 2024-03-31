#ifndef LABA16_ALGORITHMS_H
#define LABA16_ALGORITHMS_H

#include "../data_structures/matrix/matrix.h"

//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы.
//1
void swapMinMaxRows(matrix* m);

//возвращает максимальный элемент в матрице
int getMax(const int a[], const int n);

// сортирует строки матрицы m по не убыванию наибольших элементов строк
void sortRowsByMaxElement(matrix* m);

//возвращает минимальный элемент в матрице
int getMin( const int a[],const int n);

// возвращает минимальный элемент массива a размера
void sortColsByMinElement(matrix* m);

// возвращает матрицу, равную перемножению матрицы m1 на матрицу m2
matrix mulMatrices(matrix m1, matrix m2);

// заменяет исходную матрицу m, если она является симметричной, на её квадрат
void getSquareOfMatrixIfSymmetric(matrix* m);

// возвращает true, если массив a размера n состоит только из уникальных элементов
// иначе false
bool isUnique(long long int a[], int n);

// возвращает сумму элементов массива a размера n
long long int getSum(int a[], int n);

// транспонирует матрицу, если суммы строк различны
void transposeIfMatrixHasNotEqualSumOfRows(matrix* m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

#endif //LABA16_ALGORITHMS_H
