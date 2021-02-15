#include <stdio.h>
#include <stdlib.h>

#define N 4

struct Node;

struct Item {
    int key;
    int value;
    struct Node* down;
};
struct Item* new_Item(int key, int value) {
    struct Item* new = (struct Item*)malloc(sizeof(struct Item));
    new->key = key;
    new->value = value;
    new->down = NULL;

    return new;
}

struct Node {
    int n;
    struct Item* child[N];
};
struct Node* new_Node() {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->n = 0;

    return new;
}

struct Tree {
    struct Node* root;
    int height;
};
struct Tree* new_Tree() {
    struct Tree* new = (struct Tree*)malloc(sizeof(struct Tree));
    new->root = new_Node();
    new->height = 0;

    return new;
}

void _print(struct Node* current, int offset) {
    if (current == NULL)
        return;

    for (int i = 0; i < current->n; i++) {
        for (int j = 0; j < offset; j++)
            printf(" ");
        
        printf("%3d\n", current->child[i]->key);
        _print(current->child[i]->down, offset + 3);
    }
}
void print(struct Tree* t) {
    if (t->root->n == 0)
        printf("Tree is empty!\n");
    else
        _print(t->root, 0);
}

struct Item* _search(struct Node* current, int key) {
    if (current == NULL)
        return NULL;

    if (key < current->child[0]->key)
        return NULL;
    
    for (int i = 1; i < current-> n; i++) {
        if (key == current->child[i]->key)
            return current->child[i];

        if (key > current->child[i]->key)
            return _search(current->child[i-1]->down, key);
    }

    return NULL;
}
struct Item* search(struct Tree* t, int key) {
    if (t->root->n == 0)
        return NULL;

    return _search(t->root, key);
}

void insertB(struct Node* current, struct Item* new, int index) {
    for (int i = current->n; i > index; i--)
        current->child[i] = current->child[i-1];

    current->child[index] = new;
    current->n++;
}

struct Node* split(struct Node* current) {
    struct Node* new = new_Node();

    for (int i = 0; i < N/2; i++)
        new->child[i] = current->child[N/2 + i];
    
    current->n = N/2;
    new->n = N/2;

    return new;
}

struct Node* insertR(struct Node* current, int key, int value, int height) {
    if (height == 0) {
        int pos = 0;
        for (int i = 0; i < current->n; i++)
            if (current->child[i]->key > key) {
                pos = i;
                break;
            }

        insertB(current, new_Item(key, value), pos);

        if (current->n == N)
            return split(current);

        return NULL;
    } else {
        if (key < current->child[0]->key) {
            insertB(current, new_Item(key, value), 0);

            if (current->n == N)
                return split(current);
            else
                return NULL;
        } else
            for (int i = 1; i < current-> n; i++)
                if (key > current->child[i]->key)
                    return insertR(current->child[i-1], key, value, height-1);
    }

    //TODO: Non-leaf case
}