#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x;
    int mx1 = 0, mx2 = 0;       // mx1 >= mx2

    for (int i = 0; i < 10; i++) {
        scanf("%d", &x);

        if (x >= mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if (x > mx2)
            mx2 = x;
    }

    printf("%d %d\n", mx1, mx2);

    return EXIT_SUCCESS;
}