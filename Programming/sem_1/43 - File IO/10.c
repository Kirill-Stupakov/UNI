#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char* filename = "binary/double.dat";

    FILE* f = fopen(filename, "rb");

    double sum = 0;
    double a;
    while (!feof(f)) {
        fread(&a, sizeof(double), 1, f);
        printf("%lf\n", a);
        sum += a;
    }
    sum -= a;

    fclose(f);

    printf("%lf\n", sum);

    return EXIT_SUCCESS;
}
