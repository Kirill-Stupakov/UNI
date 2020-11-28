#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x; scanf("%d", &x);
    int a, b; scanf("%d %d", &a, &b);

    
    if ((x>>a & 1) ^ (x>>b & 1))
        x ^= (1<<a | 1<<b);

    printf("%d\n", x);

    return EXIT_SUCCESS;
}