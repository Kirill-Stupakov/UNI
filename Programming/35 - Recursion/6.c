#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int seq(int n) {
    if (n == 1)
        return 3;

    int q = 1;
    for (int i = 1; i < n; i++)
        q *= seq(i);
    return q-1;
}

int main() {

    return EXIT_SUCCESS;
}