#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    for (float x = 10; x <= 15; x += 0.5f)
        printf("%7.3f   -->   %17.12f\n", x, sin(x*x)*log(x));

    return EXIT_SUCCESS;
}