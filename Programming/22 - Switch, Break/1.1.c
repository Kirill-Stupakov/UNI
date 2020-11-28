#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int convert(char c) {
    int res = 1;

    switch (c) {
        case 'k':
            res = 1e3;
            break;
        case 'c':
            res = 1e5;
            break;
        case 't':
            res = 1e6;
            break;
    }

    return res;
}

int main() {
    double n;
    char from, to;
    scanf("%lf %c %c", &n, &from, &to);

    printf("%lf\n", n * convert(from) / convert(to));

    return EXIT_SUCCESS;
}