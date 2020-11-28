#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define SECOND(TYPE)                                    \
struct Node_##TYPE* second(struct Node_##TYPE* root) {  \
    return root->next;                                  \
}

NODE(int)
SECOND(int)

int main() {
    
    struct Node_int a;
    a.value = 1;

    struct Node_int b;
    b.value = 423;
    b.next = NULL;

    a.next = &b;

    printf("%d\n", second(&a)->value);

    return EXIT_SUCCESS;
}
