#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x, a; scanf("%d %d", &x, &a);

    printf("%d\n", x & (1<<a - 1) | ((x & ~((1<<(a+1))-1))>>1));

    return EXIT_SUCCESS;
}