#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char from[MAX_SIZE], to[MAX_SIZE];
    scanf("%s", from);
    scanf("%s", to);

    FILE* f = fopen(from, "r");
    FILE* t = fopen(to, "a");

    char c;
    while ((c = getc(f)) != EOF)
        putc(c, t);

    fclose(f);
    fclose(t);

    return EXIT_SUCCESS;
}
