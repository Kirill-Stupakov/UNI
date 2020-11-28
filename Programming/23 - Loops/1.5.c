#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int r; scanf("%d", &r);

    for (int y = r; y >= -r; y--) {
        for (int x = -r; x <= r; x++)
            printf(abs(x*x + y*y - r*r) <= r ? "@@" : "  ");

        printf("\n");
    }

    return EXIT_SUCCESS;
}