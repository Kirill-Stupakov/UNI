#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int _find_first_occurence(int** a, int* element, int begin, int end, int prev, int digit) {
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

int lexi_search(int** a, int size_x, int size_y, int* element) {
    int begin = 0, end = size_x - 1;
    int digit = 0;

    
}

int main() {
    int q; scanf("%d", &q);
    printf("%d\n", find_first_occurence(a, 20, q));

    return EXIT_SUCCESS;
}