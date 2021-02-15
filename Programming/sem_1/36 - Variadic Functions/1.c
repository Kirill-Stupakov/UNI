#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

double average(double n, ...) {
    va_list l;
    va_start(l, n);

    double d = va_arg(l, double);
    int count = 1;

    while (d != 0.0) {
        n += d;
        count++;

        d = va_arg(l, double);
    }

    return n/count;
}

int main() {
    printf("%lf\n", average(1.0, 2.0, 3.0, 4.0, 5.0, 0.0));

    return EXIT_SUCCESS;
}