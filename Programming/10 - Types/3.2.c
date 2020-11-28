#include <stdio.h>
#include <stdlib.h>

int main() {
    char* c = "BCDab{";

    for (int i = 0; i < 7; i++)
        printf("Code of '%c' is %3d\n", c[i], c[i]);

    return EXIT_SUCCESS;
}