#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum(int n) {
    int res = 1;

    if (n == 1)
        return 1;
    if (n <= 0)
        return 0;
    
    for (int i = 1; i < n; i++)
        res += sum(n-i);

    return res;
}

int main() {
    printf("%d\n", sum(3));

    /*
    3
    1 2
    2 1
    1 1 1

    */

    return EXIT_SUCCESS;
}