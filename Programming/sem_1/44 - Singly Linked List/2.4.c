#include <stdio.h>
#include <stdlib.h>

#define NODE(TYPE)                  \
struct Node_##TYPE {                \
    TYPE value;                     \
    struct Node_##TYPE* next;       \
};

#define FILL(TYPE, FORMAT, END)                                         \
struct Node_##TYPE* fill() {                                            \
    TYPE x; scanf(FORMAT, &x);                                          \
    struct Node_##TYPE* root = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
    struct Node_##TYPE* current = root;                                 \
    current->value = x;                                                 \
    scanf(FORMAT, &x);                                                  \
                                                                        \
    while (x != END) {                                                  \
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

#define FILL_RECURSIVE(TYPE, FORMAT)                                    \
struct Node_##TYPE* fill() {                                            \
    TYPE x; scanf(FORMAT, &x);                                          \
    struct Node_##TYPE* root = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
    if (x == NULL)                                                      \
        return NULL;                                                    \
                                                                        \
    root->value = x;                                                    \
    root->next = fill();                                                \
                                                                        \
    return root;                                                        \
}


NODE(int);
FILL(int, "%d");

int main() {
    struct Node_int* r = fill();

    while (r != NULL) {
        printf("%d ", r->value);
        r = r->next;
    }
    printf("\n");

    return EXIT_SUCCESS;
}