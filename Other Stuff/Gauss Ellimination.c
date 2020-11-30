#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    double** matrix;
    int size[2];
};

void first(struct Matrix* m, int from, int to, double l) {
    for (int i = 0; i < m->size[0]; i++)
        m->matrix[to][i] += l * m->matrix[from][i];
}

void second(struct Matrix* m, int from, int to) {
    double** t = m->matrix[from];
    m->matrix[from] = m->matrix[to];
    m->matrix[to] = t;
}

void third(struct Matrix* m, int from, double l) {
    for (int i = 0; i < m->size[0]; i++)
        m->matrix[from][i] *= l;
}

