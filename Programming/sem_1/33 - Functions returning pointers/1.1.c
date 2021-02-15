#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* minimum() {
    static int a=0, b=0, c=0;

    return (a <= b ? (a <= c ? &a : &c) : (b <= c ? &b : &c));    
}

int main() {
    int t;
    while (1) {
        scanf("%d", &t);
        *minimum() = t;
        printf("%d: %d\n", t, *minimum());
    }

    return EXIT_SUCCESS;
}