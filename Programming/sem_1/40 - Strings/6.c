#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200

char* sum(char* a, char* b) {
    char* mx = strlen(a) >= strlen(b) ? a : b;
    char* mn = strlen(a) < strlen(b) ? a : b;
    char* c = malloc((strlen(mx)+1)*sizeof(char));

    strcpy(c+1, mx);
    c[0] = '0';
    int offset = strlen(mx)-strlen(mn)+1;

    int next = 0;
    for (int i = strlen(c)-1; i >= 0; i--) {
        char q;
        if (i-offset<0)
            q = '0';
        else
            q = mn[i-offset];
        int s = c[i] + q - 2*'0' + next;
        c[i] = '0' + s%10;
        next = s/10;
    }

    if (c[0] == '0')
        c++;
        
    return c;
}

int main() {
    char a[MAX_SIZE] = {}; scanf("%s", &a);
    char b[MAX_SIZE] = {}; scanf("%s", &b);

    char* c = sum(a, b);

    printf("%s\n", c);
    return EXIT_SUCCESS;
}