#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a >= b ? a : b

struct Node {
    int key, value;
    struct Node *left_child, *right_child;
    struct Node* parent;
    int height;
};

struct Tree {
    struct Node* root;
}

int _correct_h(struct Node* current) {
    if (current == NULL)
        return 0;
    
    int height_left = _height(current->left_child);
    int height_right = _height(current->right_child);
    
    return max(height_left, height_right) + 1;
}

int _defect_h(struct Node* current) {
    return _height(current->left_child) - _height(current->right_child);
}

void _print(struct Node* current) {
    printf("Address: %p\n", current);
    printf("Key:     %d\n", current->key);
    printf("Value:   %d\n", current->value);
    printf("Height:  %d\n", current->height);
}

void _print_all(struct Node* current) {
    if (current == NULL)
        return;

    _print_all(current->left_child);
    _print(current);
    _print_all(current->right_child);
}
void print_all(struct Tree* t) {
    if (t->root == NULL)
        printf("Tree is empty!\n");
    else
        _print_all(t->root);
}

