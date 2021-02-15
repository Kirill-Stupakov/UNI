#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    // char filename[MAX_SIZE];
    // scanf("%s", filename);

    // FILE* f = fopen(filename, "r");

    char* filename = "binary/f.dat";
    FILE* f = fopen(filename, "rb");
    // int n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n[10];

    fread((char*)n, sizeof(int), 10, f);

    for (int i = 0; i < 10; i++) {
        if (n[i] == 0)
            n[i] = 5;
        printf("%d ", n[i]);
    }
    printf("\n");

    remove(filename);
    fclose(f);

    FILE* f_new = fopen(filename, "wb");

    fwrite((char*)n, sizeof(int), 10, f_new);

    fclose(f_new);

    return EXIT_SUCCESS;
}
