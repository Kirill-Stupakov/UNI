#include <stdio.h>
#include <stdlib.h>

int main() {
    float x1, y1, x2, y2;
    printf("x1 = ");    scanf("%f", &x1);
    printf("y1 = ");    scanf("%f", &y1);
    printf("x2 = ");    scanf("%f", &x2);
    printf("y2 = ");    scanf("%f", &y2);

    if (y1/x1 == y2/x2)
        printf("%.2fx + %.2fy = 0\n", -y1/x1, 1.0f);
    else
        printf("%.2fx + %.2fy + 1 = 0\n", (y2-y1)/(x2*y1-x1*y2), (x2-x1)/(x1*y2-x2*y1));

    return EXIT_SUCCESS;
}