#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void hanoi_tower(int n, int from, int through, int to) {
    if (n == 0)
        return;
    hanoi_tower(n-1, from, to, through);
    printf("%d -> %d\n", from, to);
    hanoi_tower(n-1, through, from, to);
}

int main() {
    hanoi_tower(4, 1, 2, 3);

    return EXIT_SUCCESS;
}