#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 10

void print_arr(double* a, int s) {
    for (int i = 0; i < s; i++)
        printf("%.0lf ", a[i]);

    printf("\n");
}

void offset(double* a, int f) {
    int t;
    if (f % size) {
        t = a[0];
        int i;
        for (i = 0; i+f != size; i = (i+f)%size) {
            a[i] = a[(i+f)%size];
            // print_arr(a, size);
        }
        a[i] = t;
    } else {
        for (int k = 0; k < f; k++) {
            t = a[k];
            int i;
            for (i = k; (i+f)%size != k; i = (i+f)%size) {
                a[i] = a[(i+f)%size];
                // print_arr(a, size);
            }
            a[i] = t;
        }
    }
}

int main() {
    double a[size];
    for (int i = 0; i < size; i++) {
        // scanf("%lf", a+i);
        a[i] = i;
    }

    int offs; scanf("%d", &offs);
    
    offset(a, offs);
    for (int i = 0; i < size; i++)
        printf("%.0lf ", a[i]);
    printf("\n");

    return EXIT_SUCCESS;
}