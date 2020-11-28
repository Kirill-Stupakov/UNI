#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, l; scanf("%d %d", &n, &l);

    int mx = 0;
    int res = 0;
    int mask = (1<<l)-1;
    int i = 0;

    while (mask > 0) {
        res = mask & n;
        res >>= i;
        printf("%d ", res);
        printf("%d\n", mask);

        if (res > mx)
            mx = res;

        i++;
        mask <<= 1;
    }

    printf("\n%d\n", mx);

    return EXIT_SUCCESS;
}
