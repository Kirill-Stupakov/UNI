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
    int ans = 0;
    if (t->root->right_child) {
        if (t->root->right_child->right_child)
            ans++;
        if (t->root->right_child->left_child)
            ans++;
    }

    if (t->root->left_child) {
        if (t->root->left_child->right_child)
            ans++;
        if (t->root->left_child->left_child)
            ans++;
    }

    return ans;
}

int main() {
    
}