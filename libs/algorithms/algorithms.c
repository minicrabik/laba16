#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "algorithms.h"

void swapMinMaxRows(matrix* m){
    position mx = getMaxValuePos(*m);
    position mn = getMinValuePos(*m);

    swapRows(m, mx.row_index, mn.row_index);
}
