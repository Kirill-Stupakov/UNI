#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100
#define TYPE int

int main() {
    FILE* f = fopen("textfiles/number_seq.txt", "r");
    FILE* t = fopen("textfiles/seq_sum.txt", "w");

    // for (int i = 0; i < 100; i++) {
    //     srand(i);
    //     fprintf(f, "%d ", rand() % 100);
    // }
    // fprintf(f, "\n");

    int n;
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        fscanf(f, "%d", &n);

        if (sum+n < 1000) {
            sum += n;
            fprintf(t, "%d ", n);
        } else {
            sum = n;
            fprintf(t, "\n%d ", n);
        }
    }
    fprintf(t, "\n");

    fclose(t);
    fclose(f);
    

    return EXIT_SUCCESS;
}
