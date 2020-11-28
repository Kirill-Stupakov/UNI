#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int steps(int n) {
    int ans = 0;
    for (; n > 1; ans++)
        n = n%2 ? 3*n+1 : n/2;

    return ans;
}

int main() {
    int n; scanf("%d", &n);
    printf("%d", steps(n));

    return EXIT_SUCCESS;
}