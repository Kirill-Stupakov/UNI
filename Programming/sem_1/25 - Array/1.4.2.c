#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define size 8
#define found "YES\n"
#define not_found "NO\n"

int main() {
    int board[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            scanf("%d", &board[i][j]);
    
    int a;
    for (int i = 0; i < size; i++) {            //rows
        a = 0;
        for (int j = 0; j < size; j++)
            a += board[i][j];

        if (a >= 2) {
            printf(found);
            return EXIT_SUCCESS;
        }
    }
    
    for (int i = 0; i < size; i++) {            //columns
        a = 0;
        for (int j = 0; j < size; j++)
            a += board[j][i];

        if (a >= 2) {
            printf(found);
            return EXIT_SUCCESS;
        }
    }

    for (int s = 0; s < 2*size; s++) {          //diag1
        a = 0;
        for (int i = 0; i <= s; i++)
            a += board[i][s-i];

        if (a >= 2) {
            printf(found);
            return EXIT_SUCCESS;
        }
    }

    for (int s = 0; s < 2*size; s++) {          //diag1
        a = 0;
        for (int i = 0; i <= s; i++)
            a += board[i][s-i];

        if (a >= 2) {
            printf(found);
            return EXIT_SUCCESS;
        }
    }

    for (int s = -size+1; s <= size-1; s++) {          //diag2
        a = 0;
        for (int i = 0; i <= s; i++)
            a += board[i][i-s];

        if (a >= 2) {
            printf(found);
            return EXIT_SUCCESS;
        }
    }

    printf(not_found);
    return EXIT_SUCCESS;
}