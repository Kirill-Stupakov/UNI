#include <stdio.h>
#include <stdlib.h>

int compare(double *a, double *b) {
    if (a[1]>b[1]) return 1;
    if (a[1]<b[1]) return 0;
    if (a[0]>b[0]) return 0;
    return 1;
}

void bubble(double** a, int N) {
    double c;
    for (int i=0; i < N; i++)
        for (int j=0; j < N-1; j++)
            if (compare(a[j], a[j+1]))
                for (int k=0; k<3; k++) {
                    c = a[j][k];
                    a[j][k]=a[j+1][k];
                    a[j+1][k]=c;
                }
}

int main() {
    int n;
    scanf("%d", &n);

    double** a = (double**)malloc(n*sizeof(double*));
    for (int i = 0; i < n; i++)
        a[i] = (double*)malloc(3*sizeof(double));

    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i][0]);
        scanf("%lf", &a[i][1]);
        a[i][2] = i;
    }

    bubble(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", (int)a[i][2]);
    printf("\n");

    for (int i = 0; i < n; i++)
        free(a[i]);

    free(a);

    printf("\n");

}