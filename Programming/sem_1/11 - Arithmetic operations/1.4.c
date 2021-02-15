#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long x = 1;
    for (int i = 2; i <= 20; i++)
        x *= i;
    printf("%d\n", x);

    return EXIT_SUCCESS;
}