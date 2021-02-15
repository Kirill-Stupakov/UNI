#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int counter() {
    static int t = 0;
    t++;
    
    return t;
}

int main() {
    printf("%d %d %d\n", counter(), counter(), counter());

    return EXIT_SUCCESS;
}