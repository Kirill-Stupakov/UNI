#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CRITERIA(TYPE) int criteria(struct Node_##TYPE* a) { return (a->value % 2); }

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define PRINT(TYPE, FORMAT)                                                 \
void print(struct Node_##TYPE* root, int *(func)(struct Node_##TYPE* a)) {  \
    for (int i = 0; root != NULL; i++) {                                    \
        if (func(root)) {                                                   \
            printf("%d:\t", i);                                             \
            printf(FORMAT, root->value);                                    \
            printf("\n");                                                   \
        }                                                                   \
                                                                            \
        root = root->next;                                                  \
    }                                                                       \
}


NODE(int)
CRITERIA(int)
PRINT(int, "%3d")

int main() {
    
    struct Node_int a;
    a.value = 1;

    struct Node_int b;
    b.value = 422;
    a.next = &b;

    struct Node_int c;
    c.value = 153;
    c.next = NULL;
    b.next = &c;

    print(&a, criteria);

    return EXIT_SUCCESS;
}
