#include <stdio.h>
#include <stdlib.h>

unsigned long long _representation(int a, int b) {
    if (a < 0 || b < 0)
        return 0;

    if (a+b == 1)
        return 1;

    if (a == 1 && b == 1)
        return 3;

    return _representation(a-1, b-1) + _representation(a, b-1) + _representation(a-1, b);
}

unsigned long long representation(int n) {
    return _representation(n, n);
}

int main() {
    int n; scanf("%d", &n);

    printf("%llu\n", representation(n));
    return EXIT_SUCCESS;
}