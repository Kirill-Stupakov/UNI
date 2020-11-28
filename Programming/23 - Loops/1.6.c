#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    unsigned long long int prev = 0, curr = 0;
    char x;

    for (int i = 0; i < 20; i++) {
        scanf("%c", &x);

        if (x >= '0' && x <= '9') {
            curr *= 10;
            curr += x-'0';

            prev = prev >= curr ? prev : curr;
        } else
            curr = 0;
    }

    printf("%llu\n", prev);

    return EXIT_SUCCESS;
}