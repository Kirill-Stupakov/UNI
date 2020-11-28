#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float arr[100];
    int a, b; scanf("%d %d", &a, &b);

    float* p1 = arr+a;
    float* p2 = arr+b;

    float* p3 = p1 + (p2-p1)*3/8;

    printf("%x %x: %x\n", p1, p2, p3);

    return EXIT_SUCCESS;
}