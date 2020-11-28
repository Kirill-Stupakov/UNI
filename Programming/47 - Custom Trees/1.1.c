#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; i++)
        printf("%d ", rand() % (x*4));
    
    printf("\n");

    return 0;
}