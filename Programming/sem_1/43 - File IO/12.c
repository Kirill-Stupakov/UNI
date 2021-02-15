#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

unsigned long long square(unsigned int a, unsigned int b) {
    unsigned int c = (unsigned int)pow(10, (int)(log(b)/log(10)) + 1);
    if (b == 0)
        c = 10;
    
    return ((unsigned long long)a*c + b)*((unsigned long long)a*c + b);
}

int main() {
    char* filename = "binary/sum.dat";
    unsigned int a, b; scanf("%u %u", &a, &b);
    printf("%llu\n", square(a, b));

    return EXIT_SUCCESS;
}
