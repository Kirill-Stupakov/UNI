#include <stdio.h>
#include <stdlib.h>

#define SIDE (key > current->key)
#define SIDE_N (next->key > current->key)
#define STEP 5

enum colors {
    RED,
    BLACK
};

typedef struct Node {
    int key;
    int value;
    enum colors color;
    struct Node *child[2];
    struct Node *parent;
} node;
node *new_node(int key, int value, enum colors color) {
    node *new = (node*)malloc(sizeof(node));
    new->key = key;
    new->value = value;
    new->color = color;
    new->child[0] = new->child[1] = NULL;
    new->parent = NULL;
}
node *get_parent(node *current) {
    return current == NULL ? NULL : current->parent;
}
node *get_grandparent(node *current) {
    return get_parent(get_parent(current));
}
node *get_sibling(node *current) {
    node *p = get_parent(current);

    if (get_parent(current) == NULL)
        return NULL;

    if (current == p->child[0])
        return p->child[1];
    else
        return p->child[0];
}
node *get_uncle(node *current) {
    return get_sibling(get_parent(current));
}

typedef struct Tree {
    node *root;
} tree;
tree *new_tree() {
    tree *new = (tree*)malloc(sizeof(tree));
    new->root = NULL;

    return new;
}

void _print(node* current, int offset) {
    if (current == NULL) {
        for (int i = 0; i < offset; i++)
            printf(" ");
        printf("  -\n");
        return;
    }

    _print(current->child[0], offset + STEP);

    for (int i = 0; i < offset; i++)
        printf(" ");
    printf("%3d\n", current->key);

    _print(current->child[1], offset + STEP);
}
void print(tree* t) {
    if (t->root == NULL)
        printf("Tree is empty!\n");
    else
        _print(t->root, 0);
}

node *_search(node *current, int key) {
    if (current == NULL)
        return NULL;

    if (current->key == key)
        return current;

    return _search(current->child[SIDE], key);
}
node *search(tree *t, int key) {
    return _search(t->root, key);
}

void left_rotation(node *current) {
    node *x = current->child[1];
    node *p = get_parent(current);

    current->child[1] = x->child[0];
    x->child[0] = current;
    current->parent = x;

    if (current->child[1] != NULL)
        current->child[1]->parent = current;
    
    if (p != NULL) {
        if (current == p->child[0])
            p->child[0] = x;
        else
            p->child[1] = x;
    }
    x->parent = p;
}

void right_rotation(node *current) {
    node *x = current->child[0];
    node *p = get_parent(current);

    current->child[0] = x->child[1];
    x->child[1] = current;
    current->parent = x;

    if (current->child[0] != NULL)
        current->child[0]->parent = current;
    
    if (p != NULL) {
        if (current == p->child[0])
            p->child[0] = x;
        else
            p->child[1] = x;
    }
    x->parent = p;
}

void _repair(node *current) {
    if (get_parent(current) == NULL)
        current->color = BLACK;
    else if (get_parent(current)->color == BLACK)
        return;
    else if (get_uncle(current) != NULL && get_uncle(current)->color == RED) {
        get_parent(current)->color = BLACK;
        get_uncle(current)->color = BLACK;
        get_grandparent(current)->color = RED;

        _repair(get_grandparent(current));
    } else {
        node *p = get_parent(current);
        node *g = get_grandparent(current);

        if (current == p->child[1] && p == g->child[0]) {
            left_rotation(p);
            current = current->child[0];
        } else if (current == p->child[0] && p == g->child[1]) {
            right_rotation(p);
            current = current->child[1];
        }

        p = get_parent(current);
        g = get_grandparent(current);

        if (current == p->child[0])
            right_rotation(g);
        else
            left_rotation(g);

        p->color = BLACK;
        g->color = RED;
    }
}
void _insert(node *current, node* next) {
    if (current->child[SIDE_N] == NULL) {
        current->child[SIDE_N] = next;
        next->parent = current;
    } else
        _insert(current->child[SIDE_N], next);
}
void insert(tree *t, int key, int value) {
    if (t->root == NULL)
        t->root = new_node(key, value, BLACK);
    else {
        node *next = new_node(key, value, RED);

        _insert(t->root, next);

        _repair(next);

        while (get_parent(next) != NULL)
            next = get_parent(next);
        t->root = next;
    }
}

int main() {
    tree *t = new_tree();

    int x;
    scanf("%d", &x);
    while (x) {
        insert(t, x, 0);
        printf("INSERTED!!\n");
        print(t);
        printf("\n\n");
        scanf("%d", &x);
    }
}