#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left_child, *right_child;
    struct Node* parent;
    int key;
    int value;
};
struct Node* new_Node(struct Node* parent, int key, int value) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));

    t->parent = parent;
    t->key = key;
    t->value = value;
    t->left_child = NULL;
    t->right_child = NULL;

    return t;
}

struct Tree {
    struct Node* root;
};
struct Tree* new_Tree() {
    struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree)); 
    t->root = NULL;
    
    return t;
}

struct Node* _search(struct Node* current, int key) {
    if (current == NULL)
        return NULL;
    
    if (key == current->key)
        return current;
    
    if (key < current->key)
        return _search(current->left_child, key);
    else
        return _search(current->right_child, key);
}
struct Node* search(struct Tree* t, int key) {
    if (t->root == NULL)
        return NULL;

    return _search(t->root, key);
}

void _insert(struct Node* current, int key, int value) {
    if (key < current->key)
        if (current->left_child == NULL)
            current->left_child = new_Node(current, key, value);
        else
            _insert(current->left_child, key, value);

    if (key > current->key)
        if (current->right_child == NULL)
            current->right_child = new_Node(current, key, value);
        else
            _insert(current->right_child, key, value);
}
void insert(struct Tree* t, int key, int value) {
    if (t->root == NULL)
        t->root = new_Node(NULL, key, value);
    else
        _insert(t->root, key, value);
}

void _delete(struct Node* current, int key) {
    if (current == NULL)
        return;
    
    if (key < current->key)
        _delete(current->left_child, key);

    if (key > current->key)
        _delete(current->right_child, key);
    
    if (key != current->key)
        return;
    
    if (current->left_child == NULL && current->right_child == NULL) {
        if (current->parent->left_child->key == current->key)
            current->parent->left_child = NULL;
        else
            current->parent->right_child = NULL;
        
        free(current);
    } else if (current->left_child != NULL && current->right_child != NULL) {
        struct Node* t = current->right_child;

        while (t->left_child != NULL)
            t = t->left_child;
        
        current->key = t->key;
        current->value = t->value;

        _delete(t, t->key);
    } else {
        struct Node* t;

        if (current->left_child != NULL)
            t = current->left_child;
        else
            t = current->right_child;

        current->key = t->key;
        current->value = t->value;

        _delete(t, t->key);
    }
}
void delete(struct Tree* t, int key) {
    if (t->root == NULL) {
        printf("Error: deleting from empty tree\n");
        return;
    }

    _delete(t->root, key);
}

int _is_valid(struct Node* current) {
    if (current == NULL)
        return 1;

    if (current->left_child && current->left_child->key > current->key)
        return 0;
    
    if (current->right_child && current->right_child->key < current->key)
        return 0;

    return _is_valid(current->left_child) && _is_valid(current->right_child);
}
int is_valid(struct Tree* t) {
    if (t->root == NULL)
        return -1;
    
    return _is_valid(t->root);
}

void _print(struct Node* current) {
    if (current == NULL)
        return;
    
    _print(current->left_child);
    printf("%d ", current->key);
    _print(current->right_child);
}
void print(struct Tree* t) {
    if (t->root == NULL)
        printf("Tree is empty!");
    else
        _print(t->root);

    printf("\n");
}

int main() {
    struct Tree* t = new_Tree();

    int x; scanf("%d", &x);
    while (x) {
        insert(t, x, 1);       // 20 10 15 3 4 1 8 43 2 5 24 9 0
        scanf("%d", &x);
    }

    delete(t, 20);
    print(t);
    printf("%d\n", is_valid(t));
    
    return EXIT_SUCCESS;
}