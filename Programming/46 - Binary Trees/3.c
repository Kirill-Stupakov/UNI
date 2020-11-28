#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define max(a, b) (((a) >= (b)) ? (a) : (b))
#define min(a, b) (((a) <= (b)) ? (a) : (b))

struct Node {
    struct Node *left_child, *right_child;
    int value;
};

struct Tree {
    struct Node* root;
};

struct Node* g(int value, struct Node* left_child, struct Node* right_child) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));

    new->value = value;
    new->left_child = left_child;
    new->right_child = right_child;

    return new;
}

void print(struct Node *current, int offset) {
    if(current == 0)
        return;

    print(current->right_child, offset + 3);

    for(int i = 0; i<offset; i++)
        printf(" ");

    printf("%d\n", current->value);
    print(current->left_child, offset + 3);
}

int _total(struct Node* current) {
    if (current == NULL)
        return 0;
    
    return current->value + _total(current->left_child) + _total(current->right_child);
}
int total(struct Tree* t) {
    if (t->root == NULL)
        return 0;

    return _total(t->root);
}

int _height(struct Node* current) {
    if (current == NULL)
        return 0;
    
    int h_left = _height(current->left_child);
    int h_right = _height(current->right_child);
    return 1 + max(h_left, h_right);
    
}
int height(struct Tree* t) {
    if (t->root == NULL)
        return 0;

    return _height(t->root);
}

int _minimum(struct Node* current) {
    if (current == NULL)
        return INT_MAX;
    
    int minimum_left = _minimum(current->left_child);
    int minimum_right = _minimum(current->right_child);
    int minimum_children = min(minimum_right, minimum_left);

    return min(current->value, minimum_children);

}
int minimum(struct Tree* t) {
    if (t->root == NULL)
        return 0;
    
    return _minimum(t->root);
}

double _eval(struct Node* current) {
    if (current->value > 4)
        return (double)(current->value);

    double v1 = _eval(current->left_child);
    double v2 = _eval(current->right_child);
    
    switch (current->value) {   // | 1 + | 2 - | 3 * | 4 / |
        case 1:
            return v1 + v2;
        case 2:
            return v1 - v2;
        case 3:
            return v1 * v2;
        case 4:
            return v1 / v2;
    }
}
double eval(struct Tree* t) {
    if (t->root == NULL)
        return 0;
    
    return _eval(t->root);
}

struct Node* _find(struct Node* current, int value) {
    if (current == NULL)
        return NULL;
    
    if (current->value == value)
        return current;

    struct Node* f = _find(current->left_child, value);
    if (f != NULL)
        return f;
    
    f = _find(current->right_child, value);
    if (f != NULL)
        return f;

    return NULL;
}
struct Node* find(struct Tree* t, int value) {
    if (t->root == NULL)
        return NULL;
    
    return _find(t->root, value);
}

void _destroy(struct Node* current) {
    if (current == NULL)
        return;
    
    _destroy(current->left_child);
    _destroy(current->right_child);

    free(current);
}
void destroy(struct Tree* t) {
    if (t->root != NULL)
        _destroy(t->root);
}

struct Node* _copy(struct Node* current) {
    if (current == NULL)
        return NULL;

    struct Node* c = (struct Node*)malloc(sizeof(struct Node));
    c->value = current->value;

    c->left_child = _copy(current->left_child);
    c->right_child = _copy(current->right_child);

    return c;
}
struct Tree* copy(struct Tree* t) {
    struct Tree* c = (struct Tree*)malloc(sizeof(struct Tree));
    c->root = _copy(t->root);

    return c;
}

void _reflect(struct Node* current) {
    if (current == NULL)
        return;
    
    struct Node* t = current->left_child;
    current->left_child = current->right_child;
    current->right_child = t;

    _reflect(current->left_child);
    _reflect(current->right_child);
}
void reflect(struct Tree* t) {
    if (t->root != NULL)
        _reflect(t->root);
}

int _alt_sum(struct Node* current) {
    if (current == NULL)
        return 0;
    
    return current->value + _total(current->left_child) - _total(current->right_child);
}
int alt_sum(struct Tree* t) {
    if (t->root == NULL)
        return 0;

    return _alt_sum(t->root->left_child) - _alt_sum(t->root->right_child);
}

struct Node* _input() {
    char c; scanf("%c", &c);
    if (c == '.')
        return NULL;
    
    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    int value = c - '0';
    
    scanf("%c", &c);
    while (isdigit(c)) {    // Считываем данные и откр. скобку
        value *= 10;
        value += c - '0';
        scanf("%c", &c);
    }

    current->value = value;

    current->left_child = _input();
    scanf("%c%c", &c, &c);     // пропускаем запятую и пробел
    current->right_child = _input();
    scanf("%c", &c);    // пропускаем закрывающую скобку

    return current;
}
struct Tree* input() {
    struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
    t->root = _input();

    return t;
}

#define add(a, b) g(1, a, b)
#define sub(a, b) g(2, a, b)
#define mul(a, b) g(3, a, b)
#define div(a, b) g(4, a, b) 
#define num(a) g(a, NULL, NULL)

int main() {
    struct Tree* t = input();   // 1(2(4(., .), 5(., .)), 3(6(7(., .), 8(., .)), 9(., .)))
    print(t->root, 0);

}