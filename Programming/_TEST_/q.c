#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr) {
    for (int i = 0; arr[i] != 0; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void push_back(int* arr, int n) {
    int i = 0;
    while (arr[i] != 0)
        i++;
    arr[i] = n;
    arr[i+1] = 0;
}

void pop_back(int* arr) {
    int i = 0;
    while (arr[i] != 0)
        i++;
    arr[i-1] = 0;
}

void _recursion(int* a, int last, int n) {
    if (n == 0) {
        print_arr(a);
        return; 
    }
    if (n<0)
        return;

    for (int i = last; i <= n; i++) {
        push_back(a, i);
        _recursion(a, i, n-i);
        pop_back(a);
    }
}

void bebe(int n) {
    int* a = (int*)malloc((n+1)*sizeof(int));
    a[0] = 0;
    _recursion(a, 1, n);

}

int main() {
    int n; scanf("%d", &n);

    bebe(n);

    return EXIT_SUCCESS;
}