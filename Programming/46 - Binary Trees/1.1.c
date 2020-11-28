#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left_child, right_child;
    int value;
};

struct Binary_search_tree {
    struct Node* root;
};

struct Node* rightmost(struct Binary_search_tree* t) {
    if (t->root->right_child) {
        if (t->root->right_child->right_child)
            return t->root->right_child->right_child;
        if (t->root->right_child->left_child)
            return t->root->right_child->left_child;
    }

    if (t->root->left_child) {
        if (t->root->left_child->right_child)
            return t->root->left_child->right_child;
        if (t->root->left_child->left_child)
            return t->root->left_child->left_child;
    }

    return 0;
}

int main() {
    
}