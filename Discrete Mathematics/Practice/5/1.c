#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define END '_'

void swap(char** a, char** b) {
    char* t = *b;
    *b = *a;
    *a = t; 
}
void _quick_sort(char** a, int begin, int end) {
    char* pivot = a[(begin + end) / 2];
    int i = begin, j = end;

    while (i <= j) {
        while (strcmp(a[i], pivot) < 0)
            i++;
        while (strcmp(a[j], pivot) > 0)
            j--;

        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    if (j > begin)
        _quick_sort(a, begin, j);
    if (i < end)
        _quick_sort(a, i, end);
}


void BWT_naive(char* from, char* to) {
    FILE* f = fopen(from, "r");

    //TABLE OF ROTATIONS
    fseek(f, 0, SEEK_END);
    int size = ftell(f) + 1;
    fseek(f, 0, SEEK_SET);

    char** table = (char**)malloc(size*sizeof(char*));
    for (int i = 0; i < size; i++)
        table[i] = (char*)malloc(size*sizeof(char));

    char c;
    for (int i = 0; (c = fgetc(f)) != EOF; i++) {
        table[0][i] = c;
    }
    table[0][size-1] = END;
    fclose(f);

    for (int i = 1; i < size; i++) {
        table[i][0] = table[i-1][size-1];
        for (int j = 1; j < size; j++)
            table[i][j] = table[i-1][j-1];
    }

    // printf("All rotations:\n");
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++)
    //         printf("%c", table[i][j]);
    //     printf("\n");
    // }

    // LEXICOGRAPHICAL SORT
    _quick_sort(table, 0, size-1);

    // printf("\nSorted:\n");
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++)
    //         printf("%c", table[i][j]);
    //     printf("\n");
    // }

    //LAST COLUMN
    // printf("\nResult:\n");

    FILE* t = fopen(to, "w");

    for (int i = 0; i < size; i++) {
        fprintf(t, "%c", table[i][size-1]);
        free(table[i]);
    }
    fclose(t);
    free(table);
}

int main() {
    BWT_naive("sample.txt", "transformed.txt");
}