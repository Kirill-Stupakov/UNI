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
    FILE* f = fopen("textfiles/sum.txt", "r");

    char c;
    int num = 0;
    int sum = 0;
    char prev = '0';
    
    while ((c = getc(f)) != EOF) {
        if (isdigit(c))
            num = num*10 + c-'0';
        else if (!isdigit(c) && isdigit(prev)) {
            sum += num;
            num = 0;
        } else
            num = 0;
    
        prev = c;
    }

    printf("%d\n", sum);
    
    fclose(f);

    return EXIT_SUCCESS;
}
