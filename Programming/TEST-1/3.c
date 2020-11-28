#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define min(a,b) a <= b ? a : b
#define max(a,b) a >= b ? a : b

int segment_search(double* a, int size_a, double n) {
    if (n < a[0])
        return 0;

    for (int i = 0; i < size_a-1; i++)
        if (a[i] <= n && n < a[i+1])
            return i;
        
    return size_a - 1;
}

void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

double** sum(double** a, double** b, int size_a, int size_b, int* size_res) {
    //Функции представляются в виде двумерных массивов.
    //Первая строка - координаты скачков, вторая строка - значения.
    //При этом во второй строке на один элемент больше, чем в первой.
    //Первое число второй строки - значение перед первым скачком.
    
    int size_c = size_a + size_b;

    double* c[2];
    c[0] = (double*)malloc((size_c)*sizeof(double));
    c[1] = (double*)malloc((size_c + 1)*sizeof(double));
    
    //Найдём, в каких отрезках второй функции находятся координаты скачков первой функции
    // и добавим их в выходной массив.
    c[1][0] = a[1][0] + b[1][0];
    for (int i = 0; i < size_a; i++) {
        int t = segment_search(b[0], size_b, a[0][i]);
        if (a[0][i] < b[0][0])
            t = -1;
        c[0][i] = a[0][i];
        c[1][i+1] = a[1][i+1] + b[1][t+1];
    }
    
    //То же самое со второй функцией
    for (int i = 0; i < size_b; i++) {
        int t = segment_search(a[0], size_a, b[0][i]);
        if (b[0][i] < a[0][0])
            t = -1;
        c[0][i+size_a] = b[0][i];
        c[1][i+1 + size_a] = b[1][i+1] + a[1][t+1];
    }

    // Отсортируем пузырьком по позрастанию координат скачков.
    // Значение до скачков не должно измениться.
    for (int i = 0; i < size_c; i++)
        for (int j = 0; j < size_c - 1; j++)
            if (c[0][j] > c[0][j+1]) {
                swap(&c[0][j], &c[0][j+1]);
                swap(&c[1][j+1], &c[1][j+2]);
            }

    //Значение на соседних отрезках может совпадать.
    //Тогда их нужно будет объединить.
    double empty_value = c[0][0] - 2;   //на это будем заменять удалённые отрезки
    double previous_value = c[1][0];
    for (int i = 0; i < size_c; i++) {
        if (previous_value == c[1][i+1])
            c[0][i] = empty_value;
        else
            previous_value = c[1][i+1];
    }

    int new_size = 0;
    for (int i = 0; i < size_c; i++)
        if (c[0][i] != empty_value)
            new_size++;

    double** new_c = (double**)malloc(2*sizeof(double*));
    new_c[0] = (double*)malloc((new_size)*sizeof(double));
    new_c[1] = (double*)malloc((new_size + 1)*sizeof(double));

    int k = 0;
    new_c[1][0] = c[1][0];
    for (int i = 0; i < size_c; i++)
        if (c[0][i] != empty_value) {
            new_c[0][k] = c[0][i];
            new_c[1][k+1] = c[1][i+1];
            k++;
        }

    free(c[0]);
    free(c[1]);

    *size_res = new_size;
    return new_c;
}

int main() {
    double* a[2];
    double t1[] = {-3, -1, 4};
    double t2[] = {1, 3, 6, 4};
    a[0] = t1;
    a[1] = t2;

    double* b[2];
    // double t3[] = {-5, -4, -2, 0, 2, 3, 6};
    // double t4[] = {6, 5, 4, -2, 2, 1, -3, -2};
    double t3[] = {-3, -1, 4};
    double t4[] = {7, 5, 2, 4};
    b[0] = t3;
    b[1] = t4;

    int size_c;
    double** c = sum(a, b, 3, 3, &size_c);
    
    printf("  ");
    for (int i = 0; i < size_c; i++)
        printf("%3.0lf ", c[0][i]);
    printf("\n");

    for (int i = 0; i < size_c+1; i++)
        printf("%3.0lf ", c[1][i]);
    printf("\n");

    return EXIT_SUCCESS;
}