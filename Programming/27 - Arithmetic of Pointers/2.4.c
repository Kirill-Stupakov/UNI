#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* expr(void* a) {
    int v = (int)a;
    return (void*)(v*v*v + 3*v + 1);
}

int main() {
    void* a;

    return EXIT_SUCCESS;
}