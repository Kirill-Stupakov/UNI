

#define NODE(TYPE)                  \
struct Node_##TYPE {                \
    TYPE value;                     \
    struct Node_##TYPE* next;       \
};

#define PUSH_BACK(TYPE)                                 \
void push_back(Node_##TYPE* root, TYPE n) {             \
    struct Node_##TYPE* new = (struct Node_##TYPE*)     \
    malloc(sizeof(struct Node_##TYPE));                 \
    new->value = n;                                     \
    new->next = NULL;                                   \
                                                        \
    while (root->next != NULL)                          \
        root = root->next;                              \
                                                        \
    root->next = new;                                   \
}