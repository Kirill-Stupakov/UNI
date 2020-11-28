#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a[2], b[2], c[2];
    scanf("%lf %lf", &a[0], &a[1]);
    scanf("%lf %lf", &b[0], &b[1]);
    scanf("%lf %lf", &c[0], &c[1]);

    // printf("%lf %lf\n%lf %lf\n%lf %lf\n", a[0], a[1], b[0], b[1], c[0], c[1]);

    double v1[3] = {0};
    v1[0] = b[0]-a[0];
    v1[1] = b[1]-a[1];
    v1[2] = sqrt(v1[0]*v1[0] + v1[1]*v1[1]);

    double v2[3] = {0};
    v2[0] = c[0]-a[0];
    v2[1] = c[1]-a[1];
    v2[2] = sqrt(v2[0]*v2[0] + v2[1]*v2[1]);

    // printf("%lf %lf\n%lf %lf\n", v1[0], v1[1], v2[0], v2[1]);

    double cos = (v1[0]*v2[0] + v1[1]*v2[1])/(v1[2]*v2[2]);
    double sin = sqrt(1-cos*cos);

    // printf("%lf %lf\n", cos, sin);

    double area = v1[2]*v2[2]*sin/2;
    printf("%lf\n", area);

    return EXIT_SUCCESS;
}