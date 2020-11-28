#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next, *right;
};

struct Tree {
    struct Node* root;
};

struct Node *g(int d, struct Node *s, struct Node *b) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->value = d;
    p->next = s;
    p->right = b;

    return p;
}

int children_count(struct Node* a) {
    int c = 0;
    struct Node* r = a->next;
    while (r != NULL) {
        r = r->right;
        c++;
    }

    return c;
}

int count(struct Tree* t) {
    if (t->root == NULL)
        return 0;
    int c = 0;

    struct Node* a = t->root->next;
    while (a != NULL) {
        c += children_count(a);
        a = a->right;
    }

    return c;
}

int main() {
    struct Tree t;
    t.root = g(1, g(2, g(5, 0, g(6, 0, g(7,0,0))), g(3, g(8,0,0), g(4, g(9, 0, g(10,0,0)), 0))), 0);

    printf("%d\n", count(&t));
}


