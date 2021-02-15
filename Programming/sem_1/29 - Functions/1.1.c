#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ascii_circle(int r) {
    for (int y = r; y >= -r; y--) {
        for (int x = -r; x <= r; x++)
            printf(abs(x*x + y*y - r*r) <= r ? "@@" : "  ");

        printf("\n");
    }
}

int main() {
    int r; scanf("%d", &r);
    ascii_circle(r);

    return EXIT_SUCCESS;
}