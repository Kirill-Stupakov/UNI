#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define LENGTH(TYPE)                    \
int length(struct Node_##TYPE* root) {  \
    int l = 0;                          \
                                        \
    while (root != NULL) {              \
        root = root->next;              \
        l++;                            \
    }                                   \
                                        \
    return l;                           \
}

NODE(int)
LENGTH(int)

int main() {
    
    struct Node_int a;
    a.value = 1;

    struct Node_int b;
    b.value = 2;
    b.next = NULL;

    a.next = &b;

    printf("%d\n", length(&a));

    return EXIT_SUCCESS;
}
