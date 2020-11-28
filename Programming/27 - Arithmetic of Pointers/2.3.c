#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double d = 12;
    double* p = &d;
    int a, b; scanf("%d %d", &a, &b);

    *(int*)p = a;
    *((int*)p+1) = b;

    printf("%lf\n", *p);

    return EXIT_SUCCESS;
}