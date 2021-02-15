#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int x=1, y=2, z=3;

int* access() {
    static int t = 0;
    int* ret;

    switch (t) {
        case 0:
            ret = &x;
            break;
        case 1:
            ret = &y;
            break;
        case 2:
            ret = &z;
            break;
    }

    t = (t+1)%3; 
    return ret;
}

int main() {
    int t;
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());
    printf("%d\n", *access());

    return EXIT_SUCCESS;
}