#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define q(h, m) (60*h + m)

int main() {
    int h, m; scanf("%d:%d", &h, &m);
    int t = q(h, m);

    if ((t >= q(9, 0) && t < q(13, 30)) || (t > q(14, 30) && t <= q(18, 0)))
        printf("Opened\n");
    else
        printf("Closed\n");

    return EXIT_SUCCESS;
}