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

struct Node* search(struct Tree* t, int d1, int d2) {
    if (t->root == NULL)
        return NULL;

    struct Node* q = t->root->next;
    struct Node* q2;
    while (q != NULL) {
        q2 = q->next;
        while (q2 != NULL) {
            if (q->value == d1 && q2->value == d2)
                return q;
            q2 = q2->right;
        }
        q = q->right;
    }
    return NULL;
}

int main() {
    struct Tree t;
    t.root = g(1, g(2, g(5, 0, g(6, 0, g(7,0,0))), g(3, g(8,0,0), g(4, g(9, 0, g(10,0,0)), 0))), 0);

    printf("%d\n", search(&t, 3, 8)->value);
}


