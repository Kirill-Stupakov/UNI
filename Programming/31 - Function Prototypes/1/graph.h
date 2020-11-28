#include "f.h"
#include <math.h>
#include <stdio.h>

void graph(int size_x, int size_y) {
    for (int i = -size_x/2; i <= size_x/2; i++) {
        for (int j = -size_y/2; j <= size_y/2; j++)
            printf(fabs(f(i) - j) <= 4 ? "@@" : "  ");
        printf("\n");
    }
}