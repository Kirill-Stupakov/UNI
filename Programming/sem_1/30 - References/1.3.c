#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void arith_mean(double* a, double * b, double* c) {
    double a1 = *a, b1 = *b, c1 = *c;

    *a = (b1+c1)/2;
    *b = (a1+c1)/2;
    *c = (a1+b1)/2;
}

int main() {
    double a, b, c; scanf("%lf %lf %lf", &a, &b, &c);

    arith_mean(&a, &b, &c);

    printf("%lf %lf %lf\n", a, b, c);

    return EXIT_SUCCESS;
}