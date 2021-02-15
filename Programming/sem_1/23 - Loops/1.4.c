#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char x;
    char* sub = "abc";
    int i = 0;
    int length = 0;

    do {
        scanf("%c", &x);

        if (x == sub[i]) {
            i++;
            i %= 3;
            length++;
        }
        
    } while (x != '.');

    printf("%d", length);

    return EXIT_SUCCESS;
}