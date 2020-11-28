#include <stdio.h>
#include <stdlib.h>

int digit(int x, int n) {
    return (x>>n) & 1;
}

struct Node {
    int key;
    int value;
    struct Node* child[2];
};
struct Node* new_node(int key, int value) {
    struct Node* r = (struct Node*)malloc(sizeof(struct Node));
    r->key = key;
    r->value = value;
    r->child[0] = NULL;
    r->child[1] = NULL;
}

struct Tree {
    struct Node* root;
};

void _print(struct Node* current) {
    if (current == NULL)
        return;

    _print(current->child[0]);
    printf("%d: %d\n", current->key, current->value);
    _print(current->child[1]);
}
void print(struct Tree* t) {
    if (t->root == NULL)
        printf("Error: Empty tree!\n");
    
    _print(t->root);
}

struct Node* _search(struct Node* current, int key, int depth) {
    if (current->key == key)
        return current;
    
    if (current == NULL)
        return NULL;

    int d = digit(key, depth);
    return _search(current->child[d], key, depth+1);
}
struct Node* search(struct Tree* t, int key) {
    if (t->root == NULL)
        return NULL;
    
    _search(t->root, key, 0);
}

struct Node* _insert(struct Node* current, int key, int value, int depth) {
    int d = digit(key, depth);

    if (current->child[d] == NULL)
        current->child[d] = new_node(key, value);
    else
        _insert(current->child[d], key, value, depth+1);
}
void insert(struct Tree* t, int key, int value) {
    if (t->root == NULL)
        t->root = new_node(key, value);
    else
        _insert(t->root, key, value, 0);
}

void _delete(struct Node* current, int key, int depth) {
    if (current->key == key)
        free(current);
    else
        _delete(current->child[digit(key, depth)], key, depth+1);
}
void delete(struct Tree* t, int key) {
    if (t->root == NULL)
        printf("Empty tree!\n");
    
    _delete(t->root, key, 0);
}

void count_numbers(char* filename) {
    FILE* f = fopen(filename, "r");

    struct Tree t;
    t.root = NULL;

    int x; fscanf(f, "%d", &x);
    while (!feof(f)) {
        if (search(&t, x))
            search(&t, x)->value++;
        else
            insert(&t, x, 1);
        
        fscanf(f, "%d", &x);

    }

    print(&t);
}



int main() {
    count_numbers("a.txt");
}