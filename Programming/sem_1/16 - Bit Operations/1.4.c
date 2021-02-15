#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    
    printf("%d", a&b | b&c | a&c);

    return EXIT_SUCCESS;
}