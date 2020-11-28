#include <stdio.h>
#include <stdlib.h>


void print_arr(char** a) {
    for (int i = 0; a[i][0]!=0 || a[i][1]!=0; i++)
        printf("(%d, %d) ", a[i][0], a[i][1]);
    printf("\n");
}

void push_back(char** a, char* n) {
    int i = 0;
    while (a[i][0]!=0 || a[i][1]!=0)
        i++;
    
    a[i][0] = n[0];
    a[i][1] = n[1];

    a[i+1][0] = 0;
    a[i+1][1] = 0;
}

void pop_back(char** a) {
    int i = 0;
    while (a[i][0]!=0 || a[i][1]!=0)
        i++;

    a[i-1][0] = 0;
    a[i-1][1] = 0;
}

void _print_representation(char** a, int n, int k) {
    if (n == 0 && k == 0) {
        print_arr(a);
        return;
    }
    if (n < 0 || k < 0)
        return;
    
    char t[2];
    if (n >= 1) {
        t[0] = 1;
        t[1] = 0;
        push_back(a, t);
        _print_representation(a, n-1, k);
        pop_back(a);
    }

    if (k >= 1) {
        t[0] = 0;
        t[1] = 1;
        push_back(a, t);
        _print_representation(a, n, k-1);
        pop_back(a);
    }

    if (n >= 1 && k >= 1) {
        t[0] = 1;
        t[1] = 1;
        push_back(a, t);
        _print_representation(a, n-1, k-1);
        pop_back(a);
    }
}

void print_representation(int n) {
    char** a = (char**)malloc((2*n + 1)*sizeof(char*));
    for (int i = 0; i < 2*n + 1; i++)
        a[i] = (char*)malloc(2*sizeof(char));

    a[0][0] = 0;
    a[0][1] = 0;

    _print_representation(a, n, n);

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

int main() {
    print_representation(2);
}