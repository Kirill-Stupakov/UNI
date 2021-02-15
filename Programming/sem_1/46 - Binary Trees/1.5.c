#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left_child, *right_child;
    int value;
};

struct Binary_search_tree {
    struct Node* root;
};

struct Node* leftmost_node(struct Binary_search_tree* t) {
    if (t->root == NULL)
        return 0;
    struct Node* ans = t->root;
    while (ans->left_child != NULL)
        ans = ans->left_child;

    return ans;
}