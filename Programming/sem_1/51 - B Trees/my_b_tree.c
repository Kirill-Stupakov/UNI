#include <stdio.h>
#include <stdlib.h>

#define N 4

struct Item {
    int key;
    int value;
};
struct Item* new_Item(int key, int value) {
    struct Item* new = (struct Item*)malloc(sizeof(struct Item));
    new->key = key;
    new->value = value;

    return new;
}

struct Node {
    int n;  // number of KEYS
    char is_leaf;
    struct Item* key[N + 1];
    struct Node* child[N + 1];
};
struct Node* new_Node() {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->n = 0;
    new->is_leaf = 1;
    for (int i = 0; i < N+1; i++)
        new->child[i] = NULL;

    return new;
}
int is_leaf(struct Node* current) {
    for (int i = 0; i < current->n+1; i++)
        if (current->child[i] != NULL)
            return 0;

    return 1;
}

struct Tree {
    struct Node* root;
    int depth;
};
struct Tree* new_Tree() {
    struct Tree* new = (struct Tree*)malloc(sizeof(struct Tree));
    new->depth = 0;
    new->root = new_Node();

    return new;
}

void _print(struct Node* current, int offset) {
    if (current == NULL) {
        for (int j = 0; j < offset; j++)
            printf((j-2) % 3 == 0 ? "|" : " ");
        printf("-\n");

        return;
    }

    for (int i = 0; i < current->n; i++) {
        _print(current->child[i], offset + 3);

        for (int j = 0; j < offset; j++)
            printf((j-2) % 6 == 0 ? "|" : " ");

        printf("%3d", current->key[i]->key);
        // if (is_leaf(current))
        //     printf(": %3d", current->key[i]->value);
        printf("\n");
    }
    _print(current->child[current->n], offset+3);
}
void print(struct Tree* t) {
    if (t->root->n == 0)
        printf("Tree is empty!\n");
    else
        _print(t->root, 0);
}

struct Item* _search(struct Node* current, int key) {
    int i = 0;
    for (; i < current->n; i++)
        if (key <= current->key[i]->key)
            break;

    if (is_leaf(current)) {
        if (key == current->key[i]->key)
            return current->key[i];
        else
            return NULL;
    } else
        return _search(current->child[i], key);
}
struct Item* search(struct Tree* t, int key) {
    return _search(t->root, key);
}

void split(struct Node* current) {
    struct Node* left = new_Node();
    struct Node* right = new_Node();

    left->n = N/2;
    right->n = N/2;

    for (int i = 0; i < N/2; i++) {
        left->key[i] = current->key[i];
        left->child[i] = current->child[i];
        current->key[i] = NULL;
    }
    left->child[N / 2] = current->child[N / 2];

    for (int i = N/2 + 1; i < N + 1; i++) {
        right->key[i - N/2 - 1] = current->key[i];
        right->child[i - N / 2 - 1] = current->child[i];
        current->key[i] = NULL;
    }
    right->child[N / 2] = NULL;

    current->key[0] = current->key[N/2];
    current->key[N/2] = NULL;

    current->child[0] = left;
    current->child[1] = right;
    current->n = 1;
}
struct Node* _insert(struct Node* current, int key, int value) {
    int i = 0;
    for (; i < current->n; i++)
        if (key <= current->key[i]->key)
            break;

    if (is_leaf(current)) {
        for (int j = current->n; j > i; j--)
            current->key[j] = current->key[j-1];
        current->key[i] = new_Item(key, value);
        current->n++;
    } else {
        struct Node* new = _insert(current->child[i], key, value);

        int i = 0;
        for (; i < current->n; i++)
            if (new->key[0]->key <= current->key[i]->key)
                break;
        i--;

        for (int j = current->n; j > i; j--) {
            current->key[j] = current->key[j-1];
            current->child[i+1] = current->child[i];
        }
        
        current->key[i]  = new->key[0];
        current->child[i] = new->child[0];
        current->child[i+1] = new->child[i+1];
        free(new);

        current->n++;
    }

    if (current->n == N+1) {
        split(current);
        return current;
    } else
        return NULL;
}
void insert(struct Tree* t, int key, int value) {
    struct Node *new = _insert(t->root, key, value);

    if (new != NULL)
        t->root = new;
}

int main() {
    struct Tree* t = new_Tree();
    print(t);

    // t->root->n = 4;
    // t->root->is_leaf = 0;
    // t->root->key[0] = new_Item(1, 0);
    // t->root->key[1] = new_Item(8, 0);
    // t->root->key[2] = new_Item(100, 0);
    // t->root->key[3] = new_Item(200, 0);

    // t->root->child[0] = new_Node();
    // t->root->child[0]->n = 3;
    // t->root->child[0]->key[0] = new_Item(-6, 8);
    // t->root->child[0]->key[1] = new_Item(-3, 1);
    // t->root->child[0]->key[2] = new_Item(0, 2);

    // t->root->child[2] = new_Node();
    // t->root->child[2]->n = 2;
    // t->root->child[2]->is_leaf = 0;
    // t->root->child[2]->key[0] = new_Item(9, 0);
    // t->root->child[2]->key[1] = new_Item(12, 0);

    // t->root->child[2]->child[1] = new_Node();
    // t->root->child[2]->child[1]->n = 2;
    // t->root->child[2]->child[1]->key[0] = new_Item(10, 20);
    // t->root->child[2]->child[1]->key[1] = new_Item(11, 75);

    int x;
    scanf("%d", &x);

    for (int i = 0; x; i++) {
        insert(t, x, i);
        printf("\n\n");
        print(t);
        scanf("%d", &x);
    }

    printf("\n\n");
    print(t);

    print(t);
}