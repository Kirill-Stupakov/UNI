#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double x0; scanf("%lf", &x0);

    double x = 1;
    double fact = 1, res = 0;
    double new_term = 1;
    
    for (int i = 1; new_term >= 1e-6; i++) {
        res += new_term;
        x *= x0;
        fact *= i;

        new_term = x/fact;
    }

    printf("%lf\n", res);

    return EXIT_SUCCESS;
}