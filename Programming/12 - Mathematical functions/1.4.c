#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x; scanf("%d", &x);
    printf("%d", (int)floor(log10(x))+1);

    return EXIT_SUCCESS;
}