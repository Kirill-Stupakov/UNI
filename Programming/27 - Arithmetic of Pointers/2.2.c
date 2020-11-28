#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define last_byte(a) *(char*)((int)(a+1) - 1)

int main() {
    int v = 3435435246;
    int* p = &v;

    printf("%d\n", last_byte(p));

    return EXIT_SUCCESS;
}