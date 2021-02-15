#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define side_p (key > (*current)->key)
#define side (key > current->key)
#define max(a, b) (a >= b ? a : b)

struct Node {
    int key;
    int value;

    int height;
    char upd;    //determines if height is up-to-date (bool)

    struct Node* child[2];
};
struct Node* new_Node(int key, int value) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    new->key = key;
    new->value = value;

    new->height = 0;
    new->upd = 1;

    new->child[0] = NULL;
    new->child[1] = NULL;

    return new;
}
void delete_Node(struct Node* current) {
    if (current->child[0] != NULL)
        delete_Node(current->child[0]);
    if (current->child[1] != NULL)
        delete_Node(current->child[1]);

    free(current);
}

struct Tree {
    struct Node* root;
    int height;
    int total;
};
struct Tree* new_Tree() {
    struct Tree* new = (struct Tree*)malloc(sizeof(struct Tree));

    new->root = NULL;
    new->height = -1;
    new->total = 0;

    return new;
}
void delete_Tree(struct Tree* t) {
    if (t->root != NULL)
        delete_Node(t->root);
    
    free(t);
}

int _is_valid(struct Node* current) {
    static int prev = 0;

    if (current == NULL)
        return 1;
    
    if (!_is_valid(current->child[0]))
        return 0;

    if (prev != 0 && current->key < prev)
        return 0;
    
    prev = current->key;

    return _is_valid(current->child[1]);
}
int is_valid(struct Tree* t) {
    if (t->root == NULL)
        return -1;
    
    return _is_valid(t->root);
}

void _traverse(struct Node* current) {
    if (current == NULL)
        return;

    _traverse(current->child[0]);
    printf("%d ", current->key);
    _traverse(current->child[1]);
}
void traverse(struct Tree* t) {
    if (t->root != NULL)
        _traverse(t->root);
    printf("\n");
}

struct Node* _search(struct Node* current, int key) {
    if (current == NULL)
        return NULL;

    if (current->key = key)
        return current;

    return _search(current->child[side], key);
}
struct Node* search(struct Tree* t, int key) {
    return _search(t->root, key);
}

void _print(struct Node* current, int offset) {
    if (current == NULL) {
        // printf("\n");
        return;
    }
    
    _print(current->child[1], offset + 5);

    for (int i = 0; i < offset; i++)
        printf(" ");
    // printf("%3d:   %3d\n", current->key, current->value);
    printf("%5d\n", current->key);

    _print(current->child[0], offset + 5);
}
void print(struct Tree* t) {
    if (t->root == NULL)
        printf("Tree is empty!\n");
    else
        _print(t->root, 0);
}

int height(struct Node* current) {
    if (current == NULL)
        return -1;

    int height_l, height_r;

    if (current->child[0] != NULL && current->child[0]->upd)
        height_l = current->child[0]->height;
    else
        height_l = height(current->child[0]);

    if (current->child[1] != NULL && current->child[1]->upd)
        height_r = current->child[1]->height;
    else
        height_r = height(current->child[1]);

    int h = max(height_l, height_r) + 1;

    current->height = h;
    current->upd = 1;

    return h;
}

int defect(struct Node* current) {
    return height(current->child[0]) - height(current->child[1]);
}

void left_rotation(struct Node** current) {
    struct Node* x = *current;
    struct Node* y = (*current)->child[1];
    struct Node* r = (*current)->child[1]->child[0];

    *current = y;
    (*current)->child[0] = x;
    (*current)->child[0]->child[1] = r;

    height((*current)->child[0]);
    height(*current);
}

void right_rotation(struct Node** current) {
    struct Node* x = *current;
    struct Node* y = (*current)->child[0];

    struct Node* r = (*current)->child[0]->child[1];

    *current = y;
    (*current)->child[1] = x;
    (*current)->child[1]->child[0] = r;

    height((*current)->child[1]);
    height(*current);
}

void balance(struct Node** current) {
    if (defect(*current) == -2) {
        if (defect((*current)->child[1]) >= 0)
            right_rotation(&(*current)->child[1]);
            
        left_rotation(current);
    } else if (defect(*current) == 2) {
        if (defect((*current)->child[0]) <= 0)
            left_rotation(&(*current)->child[0]);
            
        right_rotation(current);
    }
}

void _insert(struct Node** current, int key, int value) {
    (*current)->upd = 0;

    if ((*current)->child[side_p] == NULL)
        (*current)->child[side_p] = new_Node(key, value);
    else
        _insert(&(*current)->child[side_p], key, value);

    balance(current);
}
void insert(struct Tree* t, int key, int value) {
    if (t->root == NULL)
        t->root = new_Node(key, value);
    else
        _insert(&t->root, key, value);

    t->total++;
    t->height = t->root->height;
}

int _delete(struct Node* current, int key) {
    if (current == NULL)
        return 0;

    if (current->child[side] != NULL && current->child[side]->key == key) {
        if (current->child[side]->child[1] == NULL) {
            struct Node* q = current->child[side];

            current->child[side] = current->child[side]->child[0];
            free(q);
        } else {
            struct Node* q = current->child[side]->child[1];
            struct Node* w = q;

            while (q->child[0] != NULL) {
                q = q->child[0];
                if (q->child[0] != NULL)
                    w = q;
            }

            current->child[side]->key = q->key;
            current->child[side]->value = q->value;

            if (current->child[side]->child[1]->child[0] == NULL)
                current->child[side]->child[1] = current->child[side]->child[1]->child[1];
            
            w->child[0] = NULL;
            free(q);
            return 1;
        }
    } else
        return _delete(current->child[side], key);
}
int delete(struct Tree* t, int key) {
    if (t->root == NULL)
        return 0;
    if (t->root->key == key) {
        if (t->root->child[1] == NULL) {
            struct Node* q = t->root;

            t->root = t->root->child[0];
            free(q);
        } else {
            struct Node* q = t->root->child[1];
            struct Node* w = q;

            while (q->child[0] != NULL) {
                q = q->child[0];
                if (q->child[0] != NULL)
                    w = q;
            }

            t->root->key = q->key;
            t->root->value = q->value;

            if (t->root->child[1]->child[0] == NULL)
                t->root->child[1] = t->root->child[1]->child[1];
            
            w->child[0] = NULL;
            free(q);
        }
        t->total--;
        return 1;
    } else {
        int d = _delete(t->root, key);
        if (d)
            t->total--;

        return d;
    }
}

void fill_file(char* filename, int n) {
    // srand(time(NULL));
    FILE* f = fopen(filename, "w");
    for (int i = 1; i <= n; i++) {
        fprintf(f, "%d ", i);
    }
    fprintf(f, "0\n");
    fclose(f);
}

int main() {
    int q; scanf("%d", &q);
    fill_file("data.txt", q);

    struct Tree* t = new_Tree();

    FILE* f = fopen("data.txt", "r");
    int x; fscanf(f, "%d", &x);
    int i = 0;
    while (x) {
        printf("%d ", x);
        insert(t, x, i);

        fscanf(f, "%d", &x);
        i++;
    }
    printf("\n\n");
    fclose(f);
    print(t);
    // printf("\n\n");
    // scanf("%d", &x);
    // printf("\n\n");
    // delete(t, x);
    // print(t);

    traverse(t);
    printf("%d\n", is_valid(t));

    delete_Tree(t);
}