#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NODE(TYPE) struct Node_##TYPE { TYPE value; struct Node_##TYPE* next; };

#define PRINT(TYPE, FORMAT)                                         \
void print(struct Node_##TYPE* root) {                              \
    for (int i = 0; root != NULL; i++) {                            \
        printf("%d:\t", i);                                         \
        printf(FORMAT, root->value);                                \
        printf("\n");                                               \
        root = root->next;                                          \
    }                                                               \
}

NODE(int)
PRINT(int, "%3d")

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

    print(&a);

    return EXIT_SUCCESS;
}
