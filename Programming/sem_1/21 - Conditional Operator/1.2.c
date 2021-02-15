#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x1, y1; scanf("%d %d", &x1, &y1);
    int x2, y2; scanf("%d %d", &x2, &y2);
    int x3, y3; scanf("%d %d", &x3, &y3);

    int v1x = x2-x1, v1y = y2-y1;
    int v2x = x3-x2, v2y = y3-y2;

    if (fabs(v1x*v2x + v1y*v2y - sqrt(v1x*v1x + v1y*v1y)*sqrt(v2x*v2x + v2y*v2y)) <= 1e-2)
        printf("Yes\n");
    else
        printf("No\n");

    return EXIT_SUCCESS;
}