#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);

    printf("%d\n", a<b+c && b<a+c && c<a+b);

    return EXIT_SUCCESS;
}