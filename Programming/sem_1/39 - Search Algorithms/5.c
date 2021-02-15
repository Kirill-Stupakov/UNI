#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 1000000
#define VALUE_RANGE 3*SIZE
#define STEP 10
#define TESTS 1000000

void fill(int* a, int size, int max) {
    static int t = 0;
    //t += 1e10*omp_get_wtime();
    t++;
    srand(t);
    for (int i = 0; i < size; i++)
        a[i] = rand() % max;
}

int linear_search(int** a, int size_x, int size_y, int element) {
    for (int i = 0; i < size_x; i++)
        if (a[i] == element)
            return i;

    return -1;
}

int binary_search(int** a, int size_x, int size_y, int element) {
    int i = 0, j = size-1;

    while (i <= j) {
        int mid = (i+j)/2;

        if (element == a[mid])
            return mid;
        if (element > a[mid])
            i = mid+1;
        else
            j = mid-1;
    }

    return -1;
}

int main() {
    int a[SIZE];
    
    compare(a, SIZE, TESTS);
}