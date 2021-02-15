#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a, b, c; scanf("%f %f %f", &a, &b, &c);
    float d = b*b - 4*a*c;

    printf("%d\n", d > 0 ? 2 : (d == 0 ? 1 : 0));

    return EXIT_SUCCESS;
}