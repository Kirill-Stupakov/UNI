#include <stdio.h>
#include <stdlib.h>

int main() {
    int a; scanf("%d", &a);

    printf("%d\n", a/32 + (a%32 != 0));

    return EXIT_SUCCESS;
}