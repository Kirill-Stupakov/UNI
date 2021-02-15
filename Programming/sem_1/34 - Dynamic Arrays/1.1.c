#include <stdio.h>
#include <stdlib.h>
ы
#define ORDER 10

int** create_order_matrix() {
    int **ret = (int **)malloc(ORDER * sizeof(int *));
    for (int i = 0; i < ORDER; i++)
        ret[i] = (int *)calloc(ORDER, sizeof(int));

    return ret;
}

void free_order_matrix(int** matrix) {
    for (int i = 0; i < ORDER; i++)
        free(matrix[i]);

    free(matrix);
}

void print_order_matrix(int** matrix) {
    for (int i = 0; i < ORDER; i++) {
        for (int j = 0; j < ORDER; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int** create(int size) {
    int** matrix = (int**)malloc(size * sizeof(int**));

    for (int i = 0; i < size; i++) {
        int row_size = size - i;
        matrix[i] = (int **)malloc((row_size) * sizeof(int **));

        for (int j = 0; j < row_size; j++)
            matrix[i][j] = create_order_matrix();
    }

    return matrix;
}

void destroy(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++)
            free_order_matrix(matrix[i][j]);
        free(matrix[i]);
    }

    free(matrix);
}

//May return NULL
int** access(int** matrix, int size, int i, int j) {
    if (i < 0 || j < 0 || i >= size || j >= size || i > j)
        return NULL;

    return matrix[i][j - i];
}


int main() {
    int size; scanf("%d", &size);
    int **matrix = create(size);
    printf("CREATED\n");

    print_order_matrix(access(matrix, size, 2, 4));
    access(matrix, size, 2, 4)[1][3] = 7;
    print_order_matrix(access(matrix, size, 2, 4));

    destroy(matrix, size);

    return EXIT_SUCCESS;
}