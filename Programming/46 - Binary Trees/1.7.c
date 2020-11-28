#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left_child, *right_child;
    int value;
};

struct Binary_search_tree {
    struct Node* root;
};

struct Node* leftmost_leaf(struct Binary_search_tree* t) {
    if (t->root == NULL)
        return 0;
    
    struct Node* ans = t->root;
    while (ans->left_child != NULL && ans->right_child != NULL) {
        int turned = 0;
        if (!turned && ans->right_child != NULL && only_left(ans->left_child)) {
            ans = ans->right_child;
            turned = 1;
        }
        else
            ans = ans->left_child;
    }

    return ans;
}