#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define mn(a, b) a>=b ? b : a

int gcd(int a, int b) {
    int t = mn(a,b);

    while (a%t + b%t)
        t--;
    return t;
}

int* linear_gcd_representation(int a, int b) {
    int c = gcd(a, b);

    int i = 0;
    while ((double)(c-a*i)/b % 1 != 0)
        i++;

    int ret[2] = {i, (c-a*i)/b};
    return ret;
}

int main() {
    int a, b; scanf("%d %d", &a, &b);

    printf("%d\n", gcd(a, b));
    printf("%d*%d + %d*%d\n", a, linear_gcd_representation(a, b)[0], linear_gcd_representation(a, b)[1]);

    return EXIT_SUCCESS;
}