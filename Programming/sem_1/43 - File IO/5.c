#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    // char filename[MAX_SIZE];
    // scanf("%s", filename);

    // FILE* f = fopen(filename, "r");
    FILE* f = fopen("textfiles/count.txt", "r");

    char c;
    int count[256] = {0};
    
    while ((c = getc(f)) != EOF)
        count[c+128]++;
    
    fclose(f);

    for (int i = 0; i < 256; i++)
        if (count[i])
            printf("%c:\t%d\n", i-128, count[i]);

    return EXIT_SUCCESS;
}
