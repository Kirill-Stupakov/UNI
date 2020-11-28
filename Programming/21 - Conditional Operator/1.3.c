#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max3(a, b, c) (a >= b ? (a >= c ? a : c) : (b >= c ? b : c))
#define min3(a, b, c) (a <= b ? (a <= c ? a : c) : (b <= c ? b : c))

void sort3(double* a) {
    double mx = max3(a[0], a[1], a[2]);
    double mn = min3(a[0], a[1], a[2]);
    double mid = a[0] + a[1] + a[2] - mx - mn;

    a[0] = mn;
    a[1] = mid;
    a[2] = mx;
}

int main() {
    double a[3]; scanf("%lf %lf %lf", a, a+1, a+2);
    double b[3]; scanf("%lf %lf %lf", b, b+1, b+2);
    
    sort3(a);
    sort3(b);

    if (a[0]/b[0] == a[1]/b[1] && a[1]/b[1] == a[2]/b[2])
        printf("Yes\n");
    else
        printf("No\n");

    return EXIT_SUCCESS;
}