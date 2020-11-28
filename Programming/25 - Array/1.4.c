#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 8
#define found "YES\n"
#define not_found "NO\n"

int main() {
    int a;

    int row[size]={0}, column[size]={0}, diag1[2*size-1]={0}, diag2[2*size-1]={0};

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            scanf("%d", &a);
            if (a) {
                
                if (row[i]) {
                    printf(found);
                    return EXIT_SUCCESS;
                } else
                    row[i] = 1;

                if (column[j]) {
                    printf(found);
                    return EXIT_SUCCESS;
                } else
                    column[j] = 1;
                
                int d1 = i - j + size-1;
                int d2 = i + j;

                if (diag1[d1]) {
                    printf(found);
                    return EXIT_SUCCESS;
                } else {
                    diag1[d1] = 1;
                }

                if (diag2[d2]) {
                    printf(found);
                    return EXIT_SUCCESS;
                } else {
                    diag2[d2] = 1;
                }
                
            }
        }

    printf(not_found);
    return EXIT_SUCCESS;
}