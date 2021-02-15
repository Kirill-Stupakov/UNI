#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c; scanf("%f %f %f", &a, &b, &c);

    printf("%f\n", a >= b ? (a >= c ? a : c) : (b >= c ? b : c));

    return EXIT_SUCCESS;
}