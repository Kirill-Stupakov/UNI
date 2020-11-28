#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* root;
};

int is_empty(struct Stack* s) {
    return s->root == NULL;
}

void _push(struct Node* s, int element) {
    if (s->next == NULL) {
        s->next = (struct Node*)malloc(sizeof(struct Node));
        s->next->value = element;
        s->next->next = NULL;
    } else
        _push(s->next, element);
}

void push(struct Stack* s, int element) {
    if (is_empty(s)) {
        s->root = (struct Node*)malloc(sizeof(struct Node));
        s->root->value = element;
        s->root->next = NULL;
    } else
        _push(s->root, element);
}

int _pop(struct Node* s) {
    if (s->next == NULL) {
        int a = s->value;
        free(s);
        return a;
    } else
        return _pop(s->next);
}

int pop(struct Stack* s) {
    if (s->root == NULL) {
        printf("Error: pop from empty stack!\n");
        exit(1);
    }
    return _pop(s->root);
}

int main() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->root = NULL;
    
    int x; scanf("%d", &x);
    while (x) {
        push(s, x);
        scanf("%d", &x);
    }

    while (s->root != NULL)
        printf("%d ", pop(s));

}