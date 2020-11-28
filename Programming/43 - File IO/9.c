#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
#define TYPE int

void save(TYPE* arr, int size, char* filename) {
    FILE* f = fopen(filename, "wb");
    fwrite((char*)arr, sizeof(TYPE), size, f);
    
    fclose(f);
}

void load(TYPE* arr, int size, char* filename) {
    FILE* f = fopen(filename, "rb");
    fread((char*)arr, sizeof(TYPE), size, f);
    
    fclose(f);
}

int main() {
    char* filename = "binary/sum.dat";

    TYPE a[6] = {1, 1, 1, 1, 1, 1};
    save(a, 6, filename);

    return EXIT_SUCCESS;
}
