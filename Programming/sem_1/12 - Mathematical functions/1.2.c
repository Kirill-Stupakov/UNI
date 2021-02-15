#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a,b,c;
    printf("a = "); scanf("%f", &a);
    printf("b = "); scanf("%f", &b);
    printf("c = "); scanf("%f", &c);

    float p = a/2 + b/2 + c/2;
    printf("Area = %f\n", sqrt(p*(p-a)*(p-b)*(p-c)));

    return EXIT_SUCCESS;
}