#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define ACCESS(TYPE)                                                \
struct Node_##TYPE* access(struct Node_##TYPE* root, int index) {   \
    for (int i = 0; i < index; i++)                                 \
        root = root->next;                                          \
                                                                    \
    return root;                                                    \
}

NODE(int)
ACCESS(int)

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

    for (int i = 0; i < 3; i++)
        printf("%d\n", access(&a, i)->value);

    return EXIT_SUCCESS;
}
