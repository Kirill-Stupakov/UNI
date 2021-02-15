#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int counter(int next) {
    static int prev = 0;
    int t = prev;
    prev = next;
    return t;
}

int main() {
    printf("%d\n", counter(2));
    printf("%d\n", counter(7));
    printf("%d\n", counter(8));
    printf("%d\n", counter(9));

    return EXIT_SUCCESS;
}