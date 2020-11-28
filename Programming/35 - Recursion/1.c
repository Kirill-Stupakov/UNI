#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE 10

void a(int n) {
    if (n/BASE)
        a(n/BASE);
    
    printf("%d ", n%BASE);
}

void b(int n) {
    printf("%d ", n%BASE);
    if (n/BASE)
        a(n/BASE);
}

int main() {
    a(2937414);

    return EXIT_SUCCESS;
}