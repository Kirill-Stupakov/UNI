#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char* filename = "binary/sum.dat";

    FILE* f = fopen(filename, "r+b");

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);

    printf("Size = %d\n", size);

    int sum = 0;
    int a;
    while (ftell(f) < size) {
        fread(&a, sizeof(a), 1, f);
        printf("%d ", ftell(f));
        printf("NUM=%d ", a);
        sum += a;

        fseek(f, -sizeof(a), SEEK_CUR);
        printf("%d ", ftell(f));

        fwrite(&sum, sizeof(a), 1, f);
        printf("%d\n", ftell(f));
    }

    fclose(f);

    return EXIT_SUCCESS;
}
