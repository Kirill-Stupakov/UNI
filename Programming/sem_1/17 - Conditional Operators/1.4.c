#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n; scanf("%d", &n);

    printf("%s%s\n", (n&1) == (n>>1&1) ? "" : "-", n&1 ? "sin(x)" : "cos(x)");

    return EXIT_SUCCESS;
}