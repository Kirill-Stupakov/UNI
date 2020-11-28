#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a = 0x12345678;
    char* p = (char*)&a;

    printf("%x\t%x\t%x\t%x\n", &p[0], &p[1], &p[2], &p[3]);
    printf("%x\t%x\t%x\t%x\n", p[0], p[1], p[2], p[3]);

    return EXIT_SUCCESS;    //Little Endian
}