#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("%d %d %d", sizeof(int*), sizeof(char*), sizeof(double*));

    return EXIT_SUCCESS;
}