#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left_child, right_child;
    int value;
};

struct Binary_search_tree {
    struct Node* root;
};

struct Node* swap(struct Binary_search_tree* t) {
    struct Node* a = t->root->left_child->left_child;
    struct Node* b = t->root->left_child->right_child;
    struct Node* d = t->root->left_child;

    d->left_child = t->root;
    d->right_child = t->root->right_child;

    t->root->left_child = a;
    t->root->right_child = b;
    t->root = d;
}

int main() {
    
}