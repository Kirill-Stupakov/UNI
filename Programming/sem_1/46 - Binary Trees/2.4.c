#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next, *right;
};

struct Tree {
    struct Node* root;
};

void print(struct Node *r, int offset) {
    if(r == 0)
        return;
    for(int i = 0; i < offset; i++)
        printf("-");
    
    printf("%d\n", r->value);
    print(r->next, offset+3);
    print(r->right, offset);
}

struct Node *g(int d, struct Node *s, struct Node *b) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->value = d;
    p->next = s;
    p->right = b;

    return p;
}

void simplify(struct Tree* t) {
    if (t->root == NULL)
        return;

    struct Node* a = t->root->next;
    struct Node* new_child;
    struct Node* b;
    struct Node* prev;
    struct Node* tmp;
    int found = 0;
    while (a != NULL) {
        b = a->next;
        if (b != NULL && found)
            prev->right = b;
        if (b != NULL && !found) {
            new_child = b;
            found = 1;
        }
        
        while (b->right != NULL)
            b = b->right;
        
        prev = b;
        tmp = a;
        a = a->right;
        free(tmp);
    }
    t->root->next = new_child;
}

int main() {
    struct Tree t;
    t.root = g(1, g(2, g(5, 0, g(6, 0, g(7,0,0))), g(3, g(8,0,0), g(4, g(9, 0, g(10,0,0)), 0))), 0);

    simplify(&t);

    print(t.root, 0);
}


