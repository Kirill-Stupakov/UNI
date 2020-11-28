#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    // char from[MAX_SIZE], to[MAX_SIZE];
    // scanf("%s", from);
    // scanf("%s", to);

    // FILE* f = fopen(from, "r");
    // FILE* t = fopen(to, "a");

    FILE* f = fopen("textfiles/sum_lines_in.txt", "r");
    FILE* t = fopen("textfiles/sum_lines_out.txt", "w");

    char c;
    int num = 0;
    int sum = 0;
    char prev = '0';

    while ((c = getc(f)) != EOF) {
        if (c == '\n') {
            fprintf(t, "%d\n", sum);
            num = 0;
            sum = 0;
            prev = '0';
            continue;
        }

        if (isdigit(c))
            num = num*10 + c-'0';
        else if (!isdigit(c) && isdigit(prev)) {
            sum += num;
            num = 0;
        } else
            num = 0;
    
        prev = c;
    }

    fclose(f);
    fclose(t);

    return EXIT_SUCCESS;
}
