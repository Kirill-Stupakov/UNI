#include <stdio.h>
#include <stdlib.h>

#define SIDE (key > current->key)
#define SIDE_N (next->key > current->key)
#define STEP 5

enum colors {
    RED,
    BLACK
};

typedef struct node {
    int key;
    int value;
    enum colors color;
    struct node *child[2];
    struct node *parent;
} node;
node *new_node(int key, int value, enum colors color) {
    node *new = (node*)malloc(sizeof(node));
    new->key = key;
    new->value = value;
    new->color = color;
    new->child[0] = new->child[1] = NULL;
    new->parent = NULL;

    return new;
}
node *_get_parent(node *current) {
    return current == NULL ? NULL : current->parent;
}
node *_get_grandparent(node *current) {
    return _get_parent(_get_parent(current));
}
node *_get_sibling(node *current) {
    node *p = _get_parent(current);

    if (_get_parent(current) == NULL)
        return NULL;

    if (current == p->child[0])
        return p->child[1];
    else
        return p->child[0];
}
node *_get_uncle(node *current) {
    return _get_sibling(_get_parent(current));
}

typedef struct Tree {
    node *root;
} tree;
tree *new_tree() {
    tree *new = (tree*)malloc(sizeof(tree));
    new->root = NULL;

    return new;
}

void _print(node *current, int offset) {
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
void print(tree *t) {
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

void _left_rotation(node *current) {
    node *x = current->child[1];
    node *p = _get_parent(current);

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

void _right_rotation(node *current) {
    node *x = current->child[0];
    node *p = _get_parent(current);

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
    if (_get_parent(current) == NULL)
        current->color = BLACK;
    else if (_get_parent(current)->color == BLACK)
        return;
    else if (_get_uncle(current) != NULL && _get_uncle(current)->color == RED) {
        _get_parent(current)->color = BLACK;
        _get_uncle(current)->color = BLACK;
        _get_grandparent(current)->color = RED;

        _repair(_get_grandparent(current));
    } else {
        node *p = _get_parent(current);
        node *g = _get_grandparent(current);

        if (current == p->child[1] && p == g->child[0]) {
            _left_rotation(p);
            current = current->child[0];
        } else if (current == p->child[0] && p == g->child[1]) {
            _right_rotation(p);
            current = current->child[1];
        }

        p = _get_parent(current);
        g = _get_grandparent(current);

        if (current == p->child[0])
            _right_rotation(g);
        else
            _left_rotation(g);

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

        while (_get_parent(next) != NULL)
            next = _get_parent(next);
        t->root = next;
    }
}

void _delete_case_6(node* current) {
    node* s = _get_sibling(current);

    s->color = current->parent->color;
    current->parent->color = BLACK;

    if (current == current->parent->child[0]) {
        s->child[1]->color = BLACK;
        _rotate_left(current->parent);
    } else {
        s->child[0]->color = BLACK;
        _rotate_right(current->parent);
    }
}
void _delete_case_5(node* current) {
    node* s = _get_sibling(current);

    if (s->color == BLACK) {
        if ((current == current->parent->child[0]) && (s->child[1]->color == BLACK) && (s->child[0]->color == RED)) {
            s->color = RED;
            s->child[0]->color = BLACK;
            _rotate_right(s);
        } else if ((current == current->parent->child[1]) && (s->child[0]->color == BLACK) && (s->child[1]->color == RED)) {
            s->color = RED;
            s->child[1]->color = BLACK;
            _rotate_left(s);
        }
    }

    _delete_case_6(current);
}
void _delete_case_4(node* current) {
    node* s = _get_sibling(current);

    if ((current->parent->color == RED) && (s->color == BLACK) && (s->child[0]->color == BLACK) && (s->child[1]->color == BLACK)) {
        s->color = RED;
        current->parent->color = BLACK;
    } else
    _delete_case_5(current);
}
void _delete_case_3(node* current) {
    node* s = _get_sibling(current);

    if ((current->parent->color == BLACK) && (s->color == BLACK) && (s->child[0]->color == BLACK) && (s->child[1]->color == BLACK)) {
        s->color = RED;
        _delete_case_1(current->parent);
    } else
        _delete_case_4(current);
}
void _delete_case_2(node* current) {
    node* s = _get_sibling(current);

    if (s->color == RED) {
        current->parent->color = RED;
        s->color = BLACK;
        if (current == current->parent->child[0])
            _rotate_left(current->parent);
        else
            _rotate_right(current->parent);
    }

    _delete_case_3(current);
}
void _delete_case_1(node* current) {
    if (current->parent != NULL)
        _delete_case_2(current);
}
void _replace_node(node* current, node* next) {
    next->parent = current->parent;
    if (current == current->parent->child[0])
        current->parent->child[0] = next;
    else
        current->parent->child[1] = next;
}
void _delete_one_child(node* current) {
    node *child = NULL;

    if (current->child[1] == NULL)
        child = current->child[0];
    else
        child = current->child[1];

    _replace_node(current, child);
    if (current->color == BLACK) {
        if (child->color == RED)
            child->color = BLACK;
        else if (current->parent != NULL) {
            _delete_case_1(child);
        }
    }

    free(current);
}
node* _min(node* current) {
    if (current->child[0] == NULL)
        return current;
    else
        return _min(current->child[0]);
}
void _delete(node* current, int key) {
    if (current == NULL)
        return;

    if (current->key == key) {
        node *s = _min(current->child[1]);

        _replace_node(current, s);
    } else
        _delete(current->child[SIDE], key);
}
void delete(tree* t, int key) {
    if (t->root == NULL)
        return;

    _delete(t->root, key);
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