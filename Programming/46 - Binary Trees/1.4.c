#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left_child, *right_child;
    int value;
};

struct Binary_search_tree {
    struct Node* root;
};

void _insert(struct Node* current, int value) {
    if (value < current->value)
        if (current->left_child == NULL) {
            current->left_child = (struct Node*)malloc(sizeof(struct Node));
            current->left_child->value = value;
        } else
            _insert(current->left_child, value);

    if (value > current->value)
        if (current->right_child == NULL) {
            current->right_child = (struct Node*)malloc(sizeof(struct Node));
            current->right_child->value = value;
        } else
            _insert(current->right_child, value);
}
void insert(struct Binary_search_tree* t, int value) {
    if (t->root == NULL) {
        t->root = (struct Node*)malloc(sizeof(struct Node));
        t->root->value = value;
    } else
        _insert(t->root, value);
}

void _print(struct Node* current) {
    if (current == NULL)
        return;
    _print(current->left_child);
    printf("%d ", current->value);
    _print(current->right_child);
}
void print(struct Binary_search_tree* t) {
    if (t->root == NULL)
        printf("Tree is empty!");
    else
        _print(t->root);

    printf("\n");
}

struct Node* rotate_left(struct Binary_search_tree* t) {
    struct Node* a = t->root;
    struct Node* c = t->root->right_child;
    struct Node* f = t->root->right_child->left_child;

    t->root = c;
    t->root->left_child = a;
    t->root->left_child->right_child = f; 
}

int main() {

    struct Binary_search_tree t;
    t.root = NULL;

    int x; scanf("%d", &x);
    while (x) {
        insert(&t, x);
        scanf("%d", &x);
    }
    rotate_left(&t);

    print(&t);
    
}