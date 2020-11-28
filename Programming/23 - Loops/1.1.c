#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b;
    char op;
    scanf("%lf %c", &a, &op);

    do {
        scanf(" %lf", &b);

        switch(op) {
        case '+':
            a += b;
            break;
        case '-':
            a -= b;
            break;
        case '*':
            a *= b;
            break;
        case '/':
            a /= b;
            break;
        default:
            printf("Invalid operation!\n");
            return EXIT_FAILURE;
        }

        scanf(" %c", &op);
    } while (op != '=');

    printf("%lf", a);

    return EXIT_SUCCESS;
}