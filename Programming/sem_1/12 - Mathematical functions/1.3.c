#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x; scanf("%d", &x);
    printf("%d", (int)ceil(log(1e6/x)/log(1.03)));

    return EXIT_SUCCESS;
}