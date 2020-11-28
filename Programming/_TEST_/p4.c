#include <stdio.h>
#include <stdlib.h>

void print_arr(int* arr) {
    for (int i = 0; arr[i] != -1; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void push_back(int* arr, int n) {
    int i = 0;
    while (arr[i] != -1)
        i++;
    arr[i] = n;
    arr[i+1] = -1;
}

void pop_back(int* arr) {
    int i = 0;
    while (arr[i] != -1)
        i++;
    arr[i-1] = -1;
}

void _print_representation(int* arr, int n) {
    if (n == 0)
        print_arr(arr);

    for (int j = 1; j <= n; j++) {
        push_back(arr, j);

        _print_representation(arr, n-j);

        pop_back(arr);
    }
}

void print_representation(int n) {
    int* arr = (int*)malloc((n+1)*sizeof(int));
    arr[0] = -1;
    _print_representation(arr, n);
    free(arr);
}

int main() {
    int n; scanf("%d", &n);

    print_representation(n);

    return EXIT_SUCCESS;
}