#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 15
#define VALUE_RANGE 3*SIZE

int compare(int a, int b) {
    if (a == b)
        return 0;

    if ((a%2 == 0 && b%2 == 0 && a > b) ||
        (a%2 == 1 && b%2 == 1 && a < b) ||
        (a%2 == 1 && b%2 == 0))
        return 1;
    
    return -1;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void fill(int* a, int size, int max) {
    static int t = 0;
    t += time(NULL) * 3;
    t++;
    srand(t);
    for (int i = 0; i < size; i++)
        a[i] = rand() % max;
}

void print_array(int* a, int size) {
    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    printf("\n");
}

void bubble_sort(int* a, int size, int (*comp)(int, int)) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size-1; j++)
            if (comp(a[j], a[j+1]) == 1)
                swap(&a[j], &a[j+1]);
}


int main() {
    int a[SIZE];
    fill(a, SIZE, VALUE_RANGE);
    print_array(a, SIZE);
    bubble_sort(a, SIZE, compare);
    print_array(a, SIZE);

    return EXIT_SUCCESS;
}