#include <stdio.h>
#include <stdlib.h>

#define NODE(TYPE)                  \
struct Node_##TYPE {                \
    TYPE value;                     \
    struct Node_##TYPE* next;       \
};

#define FILL(TYPE, FORMAT)                                              \
struct Node_##TYPE* fill() {                                            \
    TYPE x; scanf(FORMAT, &x);                                          \
    struct Node_##TYPE* root = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
    struct Node_##TYPE* current = root;                                 \
    current->value = x;                                                 \
    scanf(FORMAT, &x);                                                  \
                                                                        \
    while (x != -1) {                                                   \
        current->next = (struct Node_##TYPE*) \
        malloc(sizeof(struct Node_##TYPE));                             \
        current = current->next;                                        \
        current->value = x;                                             \
                                                                        \
        scanf(FORMAT, &x);                                              \
    }                                                                   \
    current->next = NULL;                                               \
    return root;                                                        \
}

#define REVERSE_LIST(TYPE)                                              \
void reverse_list(struct Node_##TYPE** root) {                          \
    struct Node_##TYPE* a = *root;                                      \
    struct Node_##TYPE* b = a->next;                                    \
    struct Node_##TYPE* c = b->next;                                    \
                                                                        \
    a->next = NULL;                                                     \
                                                                        \
    while (c != NULL) {                                                 \
        b->next = a;                                                    \
        a = b;                                                          \
        b = c;                                                          \
        c = c->next;                                                    \
    }                                                                   \
                                                                        \
    b->next = a;                                                        \
    *root = b;                                                          \
}

NODE(int)
FILL(int, "%d")
REVERSE_LIST(int)

int main() {
    struct Node_int* r = fill();
    reverse_list(&r);

    while (r != NULL) {
        printf("%d ", r->value);
        r = r->next;
    }
    printf("\n");

    return EXIT_SUCCESS;
}