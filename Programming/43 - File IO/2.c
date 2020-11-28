#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* f = fopen("textfiles/g.txt", "r");

    while (!feof(f)) {
        char c[20];
        fscanf(f, "%s", c);

        int math; fscanf(f, "%d", &math);
        int phys; fscanf(f, "%d", &phys);

        printf("%s:\t\t %d\n", c, math+phys);
    }

    fclose(f);
    return EXIT_SUCCESS;
}
