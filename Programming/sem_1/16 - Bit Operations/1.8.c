#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int x; scanf("%d", &x);
    
    int i = 0;
    int n = 0;

    while ((x>>(i+1)&1) || !(x>>i & 1)) {
        i++;
        n += x>>i&1;
    }
    
    x += 1<<(i+1);
    x -= 1<<i;
    
    printf("%d\n", x);
    return EXIT_SUCCESS;
}