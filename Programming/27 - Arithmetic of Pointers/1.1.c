#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int a;
    char b;
    bool c;
    short d;
    long e;
    float f;
    double g;
    long double h;
    int i;

    printf("%d %d\n", (int)&b-(int)&a, sizeof(a));
    printf("%d %d\n", (int)&c-(int)&b, sizeof(b));
    printf("%d %d\n", (int)&d-(int)&c, sizeof(c));
    printf("%d %d\n", (int)&e-(int)&d, sizeof(d));
    printf("%d %d\n", (int)&f-(int)&e, sizeof(e));
    printf("%d %d\n", (int)&g-(int)&f, sizeof(f));
    printf("%d %d\n", (int)&h-(int)&g, sizeof(g));
    printf("%d %d\n", (int)&i-(int)&h, sizeof(h));    

    return EXIT_SUCCESS;
}