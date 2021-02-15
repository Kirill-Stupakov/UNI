#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define TYPE int

TYPE read(FILE* f, int i) {
    fseek(f, i*sizeof(TYPE), SEEK_SET);
    TYPE val;
    fread(&val, sizeof(TYPE), 1, f);

    return val;
}

void write(FILE* f, int i, TYPE val) {
    fseek(f, i*sizeof(TYPE), SEEK_SET);
    fwrite(&val, sizeof(TYPE), 1, f);
}

void swap(FILE* f, int i, int j) {
    TYPE a = read(f, i);
    TYPE b = read(f, j);

    write(f, i, b);
    write(f, j, a);
}

void _file_quick_sort(FILE* f, int begin, int end) {
    TYPE pivot = read(f, (begin+end)/2);
    int i = begin, j = end;

    while (i <= j) {
        while (read(f, i) < pivot)
            i++;
        while (read(f, j) > pivot)
            j--;

        if (i <= j) {
            swap(f, i, j);
            i++;
            j--;
        }
    }
    if (j > begin)
        _file_quick_sort(f, begin, j);
    if (i < end)
        _file_quick_sort(f, i, end);
}

void file_quick_sort(FILE* f) {
    fseek(f, 0, SEEK_END);
    int begin = 0;
    int end = ftell(f)/sizeof(TYPE)-1;

    _file_quick_sort(f, begin, end);
}

void file_counting_sort(FILE* f, FILE* t) {
    bool a[1000001] = {0};
    fseek(f, 0, SEEK_END);
    int size = ftell(f)/sizeof(TYPE);

    int q;
    for (int i = 0; i < size; i++) {
        fread(&q, sizeof(int), 1, f);
        a[q] = 1;
    }

    for (int i = 0; i <= 1000000; i++)
        if (a[i])
            fwrite(&i, sizeof(int), 1, t);
}

void file_fill(FILE* f, int size, TYPE inc) {
    TYPE val = 0;
    for (int i = 0; i < size; i++) {
        fwrite(&val, sizeof(TYPE), 1, f);
        val += inc;
    }
    
    for (int i = 0; i < size; i++) {
        srand(i*13245 - 123633);
        int ind_1 = rand() % size;
        
        srand(i*285151 - 9347524);
        int ind_2 = rand() % size;

        swap(f, ind_1, ind_2);
    }
}

int main() {
    FILE* f = fopen("binary/unsorted.bin", "w+b");
    FILE* t = fopen("binary/sorted.bin", "wb");
    int t1 = time(NULL);
    file_fill(f, (int)1e6, (TYPE)1);
    t1 -= time(NULL);
    printf("FILLED: %ds\n", -t1);

    t1 = time(NULL);
    file_counting_sort(f, t);
    t1 -= time(NULL);
    printf("SORTED: %ds\n", -t1);

    fclose(f);
    fclose(t);
    return EXIT_SUCCESS;
}
