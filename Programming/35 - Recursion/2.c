#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long factorial(int n) {
    return n<=1 ? 1 : n*factorial(n-1);
}

int coeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n-k));
}

int main() {
    printf("%d\n", coeff(20, 5));

    return EXIT_SUCCESS;
}