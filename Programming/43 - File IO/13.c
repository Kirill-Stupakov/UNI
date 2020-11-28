#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

#define MIN_ARG 0
#define MAX_ARG 20
#define NUM_FILES 10

int main() {
    char template[MAX_SIZE] = "sin/sin_";

    for (int i = 1; i <= NUM_FILES; i++) {
        char buf[MAX_SIZE];
        gcvt((double)i/NUM_FILES, 2, buf);
        char filename[MAX_SIZE];
        strcpy(filename, template);
        strcat(filename, buf);
        
        FILE* f = fopen(filename, "w");

        for (double j = MIN_ARG; j <= MAX_ARG; j += (double)i/NUM_FILES)
            fprintf(f, "%lf\t%lf\n", j, sin(j));

        fclose(f);
    }


    return EXIT_SUCCESS;
}
