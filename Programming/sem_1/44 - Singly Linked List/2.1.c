

#define NODE(TYPE)                  \
struct Node_##TYPE {                \
    TYPE value;                     \
    struct Node_##TYPE* next;       \
};

#define PUSH_FRONT(TYPE)                                \
void push_front(Node_##TYPE** root, TYPE n) {           \
    struct Node_##TYPE* new_root = (struct Node_##TYPE*)\
    malloc(sizeof(struct Node_##TYPE));                 \
                                                        \
    new_root->value = n;                                \
    new_root->next = *root;                             \
    *root = new_root;                                   \
}