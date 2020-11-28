#include <stdio.h>
#include <ctype.h>

void print_arr(int* arr) {
    int i = 0;
    while (arr[i] != -1) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void push_back(int* arr, int value) {
    int i = 0;
    while (arr[i] != -1)
        i++;
    arr[i] = value;
}

void pop_back(int* arr) {
    int i = 0;
    while (arr[i] != -1)
        i++;
    arr[i-1] = -1;
}

void day(int* arr, int n, int k, int prev) {
    if (k == 0) {
        print_arr(arr);
        return;
    }
    if (prev >= n-1)
        return;
    for (int i = prev+1; i < n; i++) {
        push_back(arr, i);
        day(arr, n, k-1, i);
        pop_back(arr);
    }
}

int main(void)
{
    int n, k;
    int arr[15];
    for (int i = 0; i < 15; i++)
        arr[i] = -1;
    scanf("%d %d", &n, &k);
    day(arr, n, k, -1);
    return 0;
}