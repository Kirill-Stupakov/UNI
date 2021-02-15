#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 5
#define coeff_size 6

int** multiply(int m[size][size], int a) {
    int res[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = a * m[i][j];

    return res;
}

int** multiply(int m1[size][size], int m2[size][size]) {
    int res[size][size] = {0};

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                res[i][j] += m1[i][k] * m2[k][j];

    return res;
}

int** add(int m1[size][size], int m2[size][size]) {
    int res[size][size] = {0};

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = m1[i][j] + m2[i][j];

    return res;
}

int main() {
    int matrix[size][size];
    int matrix0[size][size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
            matrix0[i][j] = matrix[i][j];
        }

    int coeff[coeff_size];
    for (int i = 0; i < coeff_size; i++)
        scanf("%d", &coeff[i]);

    int res[size][size] = {0};
    for (int k = 0; k < coeff_size; k++) {

    }

    return EXIT_SUCCESS;
}