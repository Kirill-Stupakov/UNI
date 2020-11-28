#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CRITERIA(TYPE) int criteria(struct Node_##TYPE* a) { return (a->value % 2); }

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define FIRST(TYPE, FORMAT)                                                 \
struct NODE_##TYPE* first(struct Node_##TYPE* root, TYPE search_val) {      \
    for (int i = 0; root != NULL; i++)                                      \
        if (root->value == search_val)                                      \
            return root;                                                    \
}

#define LAST(TYPE, FORMAT)                                                  \
struct NODE_##TYPE* last(struct Node_##TYPE* root, TYPE search_val) {       \
    struct Node_##TYPE* ret = NULL;                                         \
    for (int i = 0; root != NULL; i++)                                      \
        if (root->value == search_val)                                      \
            ret = root;                                                     \
    return ret;                                                             \
}


NODE(int)
CRITERIA(int)
FIRST(int, "%3d")

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
