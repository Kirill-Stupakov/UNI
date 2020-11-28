#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int* sum(int* a, int size_a, int* b, int size_b) {
    int* s = (int*)malloc((size_a+1)*sizeof(int));
    for (int i = 0; i < size_a; i++)
        s[i] = a[i];
    s[size_a] = 0;

    int next = 0;
    for (int i = 0; i < size_a + 1, i++) {
        int q = 0;
        if (i < size_b)
            q = s[i] + b[i] + next;
        s[i] = q%10;
        next = q/10;
    }

    return s;
}

int* 

char* product(char* a, char* b) {
    int* mx;
    int* mn;
    int mx_size, mn_size;
    if (strlen(a) >= strlen(b)) {
        mx = malloc(strlen(a)*sizeof(int));
        mx_size = strlen(a);
        for (int i = 0; i < strlen(a); i++)
            mx[i] = a[strlen(a)-i-1]-'0';

        mn = malloc(strlen(b)*sizeof(int));
        mn_size = strlen(b);
        for (int i = 0; i < strlen(b); i++)
            mn[i] = b[strlen(b)-i-1]-'0';
    } else {
        mx = malloc(strlen(b)*sizeof(int));
        mx_size = strlen(b);
        for (int i = 0; i < strlen(b); i++)
            mx[i] = b[strlen(b)-i-1]-'0';

        mn = malloc(strlen(a)*sizeof(int));
        mn_size = strlen(a);
        for (int i = 0; i < strlen(a); i++)
            mn[i] = a[strlen(a)-i-1]-'0';
    }

    for (int i = 0; i < mn_size; i++) {
        for (int j = 0; j < mx_size; j++) {
            
        }
    }

    
}

int main() {
    char a[MAX_SIZE] = {}; scanf("%s", &a);
    char b[MAX_SIZE] = {}; scanf("%s", &b);

    char* c = sum(a, b);

    printf("%s\n", c);
    return EXIT_SUCCESS;
}