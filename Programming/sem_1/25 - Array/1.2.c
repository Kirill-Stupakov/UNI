#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define point_number 15

int main() {
    srand(time(NULL));

    int p[point_number][2];
    for (int i = 0; i < point_number; i++) {
        p[i][0] = rand() % 201 - 100;
        p[i][1] = rand() % 201 - 100;

        printf("%2d:   %4d %4d\n", i, p[i][0], p[i][1]);
    }

    double max_dist = 0;
    for (int i = 0; i < point_number - 1; i++)
        for (int j = i+1; j < point_number; j++) {
            int x = p[i][0] - p[j][0];
            int y = p[i][1] - p[j][1];
            double dist = x*x + y*y;

            if (dist > max_dist) {
                max_dist = dist;
                printf("%d %d\n", i, j);
            }
        }

    printf("%lf\n", sqrt(max_dist));

    return EXIT_SUCCESS;
}