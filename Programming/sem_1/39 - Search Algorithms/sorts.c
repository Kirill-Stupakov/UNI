#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 15
#define VALUE_RANGE 3*SIZE
#define SEPARATOR_SIZE 4*SIZE

void fill(int* a, int size, int max) {
    static int t = 0;
    t += time(NULL) * 3;
    t++;
    srand(t);
    for (int i = 0; i < size; i++)
        a[i] = rand() % max;
}

void print_array(int* a, int size) {
    for (int i = 0; i < size; i++)
        printf("%3d ", a[i]);
    printf("\n");
}

void print_separator(int size) {
    for (int i = 0; i < size; i++)
        printf("=");
    printf("\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int* a, int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size-1; j++)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

void selection_sort(int* a, int size) {
    for (int i = 0; i < size-1; i++) {
        int mn = a[i];
        int index = i;
        for (int j = i+1; j < size; j++)
            if (a[j] < mn) {
                mn = a[j];
                index = j;
            }
        swap(&a[i], &a[index]);
    }
}

void selection_sort_network(int* a, int size) {
    for (int i = 0; i < size-1; i++)
        for (int j = i+1; j < size; j++)
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
}

void insertion_sort(int* a, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i; a[j] >= a[j+1] && j >= 0; j--)
            swap(&a[j], &a[j+1]);
    }
}

void insertion_sort_network(int* a, int size) {
    for (int i = 0; i < size-1; i++)
        for (int j = i; j >= 0; j--)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}

void _radix_sort(int* a, int size, int base) {
    int** t = (int**)malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) {
        t[i] = (int*)malloc(base*sizeof(int));
        for (int j = 0; j < base; j++)
            t[i][j] = -1;
    }

    int mx = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > mx)
            mx = a[i];

    int max_length = (int)floor((log(mx)/log(base))) + 1;

    for (int cycle = 0; cycle < max_length; cycle++) {
        for (int i = 0; i < size; i++) {
            int digit = (a[i] % (int)pow(base, cycle+1)) / (int)pow(base, cycle);
            t[i][digit] = a[i];
        }
        
        int q = 0;
        for (int i = 0; i < base; i++)
            for (int j = 0; j < size; j++)
                if (t[j][i] != -1) {
                    a[q] = t[j][i];
                    q++;
                    t[j][i] = -1;
                }

    }

    for (int i = 0; i < size; i++)
        free(t[i]);
    free(t);
}

void radix_sort(int* a, int size) {
    _radix_sort(a, size, 10);
}

void _quick_sort(int* a, int begin, int end) {
    int pivot = a[(begin + end) / 2];
    int i = begin, j = end;

    while (i <= j) {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }

    if (j > begin)
        _quick_sort(a, begin, j);
    if (i < end)
        _quick_sort(a, i, end);
}

void quick_sort(int* a, int size) {
    _quick_sort(a, 0, size-1);
}

void _merge(int* a, int begin1, int end1, int begin2, int end2) {
    int* t = (int*)malloc((end2-begin1+1)*sizeof(int));

    int i = begin1, j = begin2;
    int index = 0;

    while (i <= end1 && j <= end2) {
        if (a[i] <= a[j]) {
            t[index] = a[i];
            i++;
        } else {
            t[index] = a[j];
            j++;
        }

        index++;
    }
    
    for (; i <= end1; i++) {
        t[index] = a[i];
        index++;
    }
    for (; j <= end2; j++) {
        t[index] = a[j];
        index++;
    }

    for (int k = 0; k < (end2-begin1+1); k++)
        a[begin1+k] = t[k];

    free(t);
}

void _merge_sort(int* a, int begin, int end) {
    if (end-begin <= 0)
        return;
    
    int mid = (begin+end) / 2;
    _merge_sort(a, begin, mid);
    _merge_sort(a, mid+1, end);

    _merge(a, begin, mid, mid+1, end);
}

void merge_sort(int* a, int size) {
    _merge_sort(a, 0, size-1);
}

void heapify(int* a, int begin, int end) {
    int left = begin*2 + 1, right = begin*2 + 2;

    if ((a[begin] >= a[left] || left > end) && (a[begin] >= a[right] || right > end))
        return;
    
    if (right > end) {
        if (a[begin] < a[left]) {
            swap(&a[begin], &a[left]);
            heapify(a, left, end);
        }
    } else
        if (a[left] >= a[right]) {
            if (a[begin] < a[left]) {
                swap(&a[begin], &a[left]);
                heapify(a, left, end);
            }
        } else
            if (a[begin] < a[right]) {
                swap(&a[begin], &a[right]);
                heapify(a, right, end);
            }
}

void build_max_heap(int* a, int size) {
    for (int i = size/2; i >= 0; i--)
        heapify(a, i, size-1);
}

void heap_sort(int* a, int size) {
    build_max_heap(a, size);

    for (int end = size-1; end>0; end--) {
        swap(&a[0], &a[end]);
        heapify(a, 0, end-1);
    }
}

int main() {
    int a[SIZE];
    print_separator(SEPARATOR_SIZE);

    char* s[] = {"BUBBLE SORT", "SELECTION SORT", "SELECTION SORT NETWORK", "INSERTION SORT", "INSERTION SORT NETWORK", "RADIX SORT", "QUICK SORT", "MERGE SORT", "HEAP SORT"};
    void (*f[])(int*, int) = {bubble_sort, selection_sort, selection_sort_network, insertion_sort, insertion_sort_network, radix_sort, quick_sort, merge_sort, heap_sort};

    for (int i = 0; i < 9; i++) {
        fill(a, SIZE, VALUE_RANGE);
        printf("%s\n", s[i]);
        print_array(a, SIZE);
        f[i](a, SIZE);
        print_array(a, SIZE);
        print_separator(SEPARATOR_SIZE);
    }

    return EXIT_SUCCESS;
}