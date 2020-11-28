#include <stdio.h>
#include <stdlib.h>

#define min(a, b) a <= b ? a : b
#define max(a, b) a >= b ? a : b

int intersect(double* a, double* b) {
    return a[0] <= b[0] && b[0] <= a[1] || a[0] <= b[1] && b[1] <= a[1];
}

void unify(double* a, double* b) {
    a[0] = min(a[0], b[0]);
    a[1] = max(a[1], b[1]);
}

void make_invalid(double* a) {
    a[0] = 1;
    a[1] = 0;
}

int is_valid(double* a) {
    return a[0] <= a[1];
}

void count() {
    static int t = 0;
    printf("%d\n", t);
    t++;
}

void print_valid(double** a, int size) {
    for (int i = 0; i < size; i++)
        if (is_valid(a[i]))
            printf("%lf\t%lf\n", a[i][0], a[i][1]);
    printf("\n\n");
}

double** _union(double** a, double** b, int size_a, int size_b, int* size_t) {

    //Create result set T.
    double** t = (double**)malloc((size_a + size_b)*sizeof(double*));
    for (int i = 0; i < size_a + size_b; i++)
        t[i] =(double*)malloc(2*sizeof(double));

    // count();
    //Fill T with extended versions of vectors from set A
    for (int i = 0; i < size_a; i++) {
        t[i][0] = a[i][0];
        t[i][1] = a[i][1];

        for (int j = 0; j < size_b; j++)
            if (intersect(t[i], b[j]))
                unify(t[i], b[j]);
    }

    // count();
    //Same with set B
    for (int i = 0; i < size_b; i++) {
        t[size_a + i][0] = b[i][0];
        t[size_a + i][1] = b[i][1];

        for (int j = 0; j < size_a; j++)
            if (intersect(t[size_a + i], a[j]))
                unify(t[size_a + i], a[j]);
    }

    // count();
    //We might have overlapping segments in set T. Delete them, making unused vectors invalid (1, 0)
    int reduced;
    do {
        reduced = 0;
        for (int i = 0; i < size_a + size_b - 1; i++)
            if (is_valid(t[i]))
                for (int j = i+1; j < size_a + size_b; j++)
                    if (intersect(t[i], t[j]) && is_valid(t[j])) {
                        unify(t[i], t[j]);
                        make_invalid(t[j]);
                        reduced = 1;
                    }
    } while (reduced);

    // count();
    //Calculate size of new set
    int new_size = 0;
    for (int i = 0; i < size_a + size_b; i++)
        if(is_valid(t[i]))
            new_size++;

    // count();
    //Create new set
    double** new_array = (double**)malloc(new_size*sizeof(double*));
    for (int i = 0; i < new_size; i++)
        new_array[i] = (double*)malloc(2*sizeof(double));

    // count();
    //Fill it
    int k = 0;
    for (int i = 0; i < size_a + size_b; i++)
        if (is_valid(t[i])) {
            new_array[k][0] = t[i][0];
            new_array[k][1] = t[i][1];
            k++;
        }
    
    // count();
    //Free T from previous elements
    for (int i = 0; i < size_a + size_b; i++)
        free(t[i]);
    free(t);

    // count();
    //Update T and its size
    t = new_array;
    *size_t = new_size;

    return t;
}

int main() {
    int size_a = 8;
    int size_b = 3;

    printf("A:\n");
    double** a = (double**)malloc(size_a*sizeof(double*));
    for (int i = 0; i < size_a; i++) {
        a[i] = (double*)malloc(2*sizeof(double));
        scanf("%lf", &a[i][0]);
        scanf("%lf", &a[i][1]);
    }

    printf("B:\n");
    double** b = (double**)malloc(size_b*sizeof(double*));
    for (int i = 0; i < size_b; i++) {
        b[i] = (double*)malloc(2*sizeof(double));
        scanf("%lf", &b[i][0]);
        scanf("%lf", &b[i][1]);
    }

    int size_c;
    double** c = _union(a, b, size_a, size_b, &size_c);

    for (int i = 0; i < size_c; i++)
        printf("%lf\t%lf\n", c[i][0], c[i][1]);

    return 0;
}