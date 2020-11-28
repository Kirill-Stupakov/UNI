#include <stdio.h>
#include <stdlib.h>


struct Stack {
    int* root;
    int size;
    int allocated_size;
};

int is_empty(struct Stack* s) {
    return s->size == 0;
}

void push(struct Stack* s, int element) {
    if (is_empty(s)) {
        s->root = (int*)malloc(sizeof(int));
        s->allocated_size = 1;
    }

    if (s->size == s->allocated_size) {
        s->allocated_size *= 2;
        int* new = (int*)malloc(s->allocated_size*sizeof(int));
        for (int i = 0; i < s->size; i++)
            new[i] = s->root[i];
        free(s->root);
        s->root = new;
    }

    s->size++;
    s->root[s->size-1] = element;
}

int pop(struct Stack* s) {
    if (is_empty(s)) {
        printf("Error: Stack is empty!");
        return NULL;
    }

    int a = s->root[s->size];
    s->size--;
    return a;
}

int main() {
    struct Stack a;
    a.size = 0;

    int x; scanf("%d", &x);

    while (x) {
        push(&a, x);
        scanf("%d", &x);
    }

    while (a.size)
        printf("%d ", pop(&a));
    printf("\n");
}