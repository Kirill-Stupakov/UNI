#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x; scanf("%d", &x);
    int y = 0;

    for (int i = 1; x; i *= 10) {
        y += i*(x%8);
        x /= 8;
    }
    
    printf("%d", y);

    return EXIT_SUCCESS;
}