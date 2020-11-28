

#define NODE(TYPE)                  \
struct Node_##TYPE {                \
    TYPE value;                     \
    struct Node_##TYPE* next;       \
};

#define INSERT(TYPE)                                        \
void insert(Node_##TYPE** root, int index, TYPE value) {    \
    struct Node_##TYPE* r = *root;                          \
    struct Node_##TYPE* new = (struct Node_##TYPE*)         \
    malloc(sizeof(struct Node_##TYPE));                     \
    new->value = value;                                     \
                                                            \
    int i = 0;                                              \
    while (i<index) {                                       \
        i++;                                                \
        (*root) = (*root)->next;                            \
    }                                                       \
                                                            \
    new->next = (*root)->next;                              \
    (*root)->next = new;                                    \
}