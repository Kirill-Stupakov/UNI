#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int p(int n, int k) {
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    if (k%2 == 0)
        return p(n*n, k/2);
    else
        return p(n, k-1)*n;
}

int main() {
    printf("%d\n", p(2, 10));

    return EXIT_SUCCESS;
}