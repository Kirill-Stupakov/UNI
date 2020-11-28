#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    FILE* f = fopen("textfiles/f.txt", "w");
    fprintf(f, "x\t\tsin(x)\n");
    for (double i = 0; i < 2*M_PI; i += 0.05)
        fprintf(f, "%.2lf\t\t%lf\n", i, sin(i));

    fclose(f);
    return EXIT_SUCCESS;
}
