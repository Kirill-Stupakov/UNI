#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int m) {
    static int a=0, b=0, c=0;
    a=b;
    b=c;
    c=m;
    return a+b+c;
}

int main() {
    printf("%d\n", sum(3));
    printf("%d\n", sum(4));
    printf("%d\n", sum(5));
    printf("%d\n", sum(6));
    printf("%d\n", sum(7));

    return EXIT_SUCCESS;
}