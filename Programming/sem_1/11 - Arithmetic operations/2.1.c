#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; scanf("%d", &x);

    printf("%c", 'A' + (99-x)/10);

    return EXIT_SUCCESS;
}