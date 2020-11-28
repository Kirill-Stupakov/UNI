#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pw(double* n, int p) {
    double n0 = *n;
    for (int i = 1; i < p; i++)
        *n *= n0;
}

int main() {
    double n; scanf("%lf", &n);
    pw(&n, 5);
    printf("%lf", n);

    return EXIT_SUCCESS;
}