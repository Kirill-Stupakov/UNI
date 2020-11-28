#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n; scanf("%d", &n);

    printf("%d\n", n&1 ? -1 : 1);

    return EXIT_SUCCESS;
}