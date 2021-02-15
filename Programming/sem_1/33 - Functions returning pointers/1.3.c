#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN_DIFF 1e-10

double* f(int p) {
    static double n = 1;
    static double power = 1;
    static double n_pow = 1;

    if (fabs(n_pow-pow(n, power)) > MIN_DIFF)
        n = pow(n_pow, 1.0/power);
    
    power = p;
    n_pow = pow(n, power);

    return &n_pow;
}

int main() {
    *f(2) = 25;
    printf("%lf\n", *f(3));

    *f(10) = 1024;
    printf("%lf\n", *f(5));

    return EXIT_SUCCESS;
}