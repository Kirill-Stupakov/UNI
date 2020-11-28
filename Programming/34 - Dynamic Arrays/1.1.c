#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ORDER 10

int** create(int size) {
    int** matrix = (int**)malloc(size*sizeof(int**));

    for (int i = 0; i < size; i++) {
        matrix[i] = (int**)malloc(sizeof(int**));

        int** sqr = (int**)malloc(ORDER * sizeof(int*));
        for (int j = 0; j < ORDER; j++) {
            sqr[j] = (int*)malloc(ORDER * sizeof(int));

            for (int k = 0; k < ORDER; k++)
                *(sqr+j+k) = 0;
        }

        matrix[i] = sqr;
    }

    return matrix;
}

int** access(int** matrix, int size, int i, int j) {
    static int dummy;
    dummy = 0;

    if (i < 0 || j < 0 || i >= size || j >= size)
        exit(1);
    
    if (i != j)
        return &dummy;
    
    return &matrix[i];
}

void destroy(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < ORDER; j++)
            free(matrix[i][j]);

        free(matrix[i]);
    }

    free(matrix);
}

int main() {
    int size; scanf("%d", &size);
    int** matrix = create(size);
    access(matrix, size, 1, 1)[2][5] = 3;
    printf("CREATED\n");
    // access(matrix, size, 1, 1)[1][5] = 4;

    printf("%d %d\n", access(matrix, size, 1, 1)[1][5], access(matrix, size, 1, 1)[2][5]);
    destroy(matrix, size);

    return EXIT_SUCCESS;
}