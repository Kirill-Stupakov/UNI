#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int _find_first_occurence(int* a, int element, int begin, int end, int prev) {
    if (begin > end)
        return prev;
    
    int mid = (begin+end) / 2;

    if (a[mid] == element)
        return _find_first_occurence(a, element, begin, mid-1, mid);
    
    if (element > a[mid])
        return _find_first_occurence(a, element, mid+1, end, prev);
    else
        return _find_first_occurence(a, element, begin, mid-1, prev);
}

int find_first_occurence(int* a, int size, int element) {
    _find_first_occurence(a, element, 0, size-1, -1);
}

int main() {
    int a[] = {0, 3, 5, 5, 5, 5, 5, 5, 5, 7, 8, 9, 10, 11, 11, 11, 11, 19, 20, 21};

    int q; scanf("%d", &q);
    printf("%d\n", find_first_occurence(a, 20, q));

    return EXIT_SUCCESS;
}