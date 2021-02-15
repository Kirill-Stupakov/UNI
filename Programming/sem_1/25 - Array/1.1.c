#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define width 50
#define height 20

int main() {
    srand(time(NULL));

    int a[width];
    for (int i = 0; i < width; i++)
        a[i] = rand() % (height+1);

    for (int i = height; i >= 0; i--) {
        for (int j = 0; j < width; j++)
            printf(a[j] >= i ? "@" : " ");

        printf("\n");
    }

    return EXIT_SUCCESS;
}