#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>

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

int linear_search(int* a, int size, int element) {
    for (int i = 0; i < size; i++)
        if (a[i] == element)
            return i;

    return -1;
}

int binary_search(int* a, int size, int element) {
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

int interpolation_search(int* a, int size, int element) {
    int i = 0, j = size-1;

    while (i <= j) {
        int mid = i + (int)round((j-i) * (double)(element - a[i]) / (double)(a[j] - a[i]));
        if (mid < i)
            mid = i;
        if (mid > j)
            mid = j;

        if (element == a[mid])
            return mid;
        if (element > a[mid])
            i = mid+1;
        else
            j = mid-1;
    }

    return -1;
}

void compare(int* a, int size, int tests) {
    printf("LINEAR SEARCH:\t\t");
    double time = omp_get_wtime();
    fill(a, size, 1000);
    for (int i = 0; i < tests; i++)
        linear_search(a, size, a[rand()%size]);

    time -= omp_get_wtime();
    printf("%lf ms\n", -time/tests*1e3);

    printf("BINARY SEARCH:\t\t");
    time = omp_get_wtime();
    fill(a, size, 1000);
    for (int i = 0; i < tests; i++)
        binary_search(a, size, a[rand()%size]);

    time -= omp_get_wtime();
    printf("%lf ms\n", -time/tests*1e3);

    printf("INTERPOLATION SEARCH:\t");
    time = omp_get_wtime();
    fill(a, size, 1000);
    for (int i = 0; i < tests; i++)
        interpolation_search(a, size, a[rand()%size]);

    time -= omp_get_wtime();
    printf("%lf ms\n", -time/tests*1e3);
}

int main() {
    int a[SIZE];
    
    compare(a, SIZE, TESTS);
}