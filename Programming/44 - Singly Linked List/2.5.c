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
    while (x) {                                                         \
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

#define COPY_RECURSIVE(TYPE)                                            \
struct Node_##TYPE* copy(struct Node_##TYPE* x) {                       \
    if (x == NULL)                                                      \
        return NULL;                                                    \
                                                                        \
    struct Node_##TYPE* root = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
                                                                        \
    root->value = x->value;                                             \
    root->next = copy(x->next);                                         \
                                                                        \
    return root;                                                        \
}


NODE(int);
FILL(int, "%d");
COPY_RECURSIVE(int)

int main() {
    struct Node_int* k = fill();
    struct Node_int* r = copy(k);

    while (r != NULL) {
        printf("%d ", r->value);
        r = r->next;
    }
    printf("\n");

    return EXIT_SUCCESS;
}