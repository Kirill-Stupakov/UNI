#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define LAST(TYPE)                                      \
struct Node_##TYPE* last(struct Node_##TYPE* root) {     \
    while (root->next != NULL)                          \
        root = root->next;                              \
                                                        \
    return root;                                        \
}

NODE(int)
LAST(int)

int main() {
    
    struct Node_int a;
    a.value = 1;

    struct Node_int b;
    b.value = 423;
    a.next = &b;

    struct Node_int c;
    c.value = 153;
    c.next = NULL;
    b.next = &c;

    printf("%d\n", last(&a)->value);

    return EXIT_SUCCESS;
}
