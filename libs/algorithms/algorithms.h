#ifndef LABA16_ALGORITHMS_H
#define LABA16_ALGORITHMS_H

#include "../data_structures/matrix/matrix.h"

//Дана квадратная матрица, все элементы которой различны. Поменять местами
//строки, в которых находятся максимальный и минимальный элементы.
//1
void swapMinMaxRows(matrix* m);

//возвращает максимальный элемент в матрице
int getMax(const int a[], const int n);

void sortRowsByMaxElement(matrix* m);

#endif //LABA16_ALGORITHMS_H
