#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_representation(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("(1, 1) ");
        for (int j = i; j < n; j++)
            printf("(0, 1) (1, 0) ");

        printf("\n");
    }
}

int main() {
    print_representation(4);

    return EXIT_SUCCESS;
}