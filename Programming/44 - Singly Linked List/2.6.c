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

#define COPY_RECURSIVE_REVERSED(TYPE)                                   \
struct Node_##TYPE* _copy(struct Node_##TYPE* x, struct Node_##TYPE* nxt) { \
    if (x == NULL)                                                      \
        return nxt;                                                     \
                                                                        \
    nxt->value = x->value;                                              \
                                                                        \
    struct Node_##TYPE* q = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
    q->next = nxt;                                                      \
                                                                        \
    return _copy(x->next, q);                                           \
}                                                                       \
                                                                        \
struct Node_##TYPE* copy(struct Node_##TYPE* x) {                       \
    if (x == NULL)                                                      \
        return NULL;                                                    \
                                                                        \
    struct Node_##TYPE* q = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                                 \
    q->next = NULL;                                                     \
                                                                        \
    struct Node_##TYPE* t = _copy(x, q);                                \
    struct Node_##TYPE* t1 = t->next;                                   \
                                                                        \
    free(t);                                                            \
    return t1;                                                          \
}


NODE(int);
FILL(int, "%d");
COPY_RECURSIVE_REVERSED(int)

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