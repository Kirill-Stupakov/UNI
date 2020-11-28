#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 10 2 3 * -
#define MAX_SIZE 100

void count() {
    static int t = 0;
    printf("COUNT: %d\n", t);
    t++;
}

int reverse_polish_notation(char* s) {
    int* a = (int*)malloc(MAX_SIZE*sizeof(int));
    int top = -1;

    int x = 0;
    int res;
    for (int i = 0; i < strlen(s); i++) {
        if (isdigit(s[i])) {
            x = 10*x + s[i]-'0';
            if (s[i+1] == ' ') {
                top++;
                a[top] = x;
                x = 0;
            }
        } else if (s[i] != ' ') {
            switch(s[i]) {
                case '+':
                    res = a[top-1] + a[top];
                    break;
                case '-':
                    res = a[top-1] - a[top];
                    break;
                case '*':
                    res = a[top-1] * a[top];
                    break;
                case '/':
                    res = a[top-1] / a[top];
                    break;
            }
            top--;
            a[top] = res;
        }
    }

    return a[top];
    free(a);
}

int main() {
    printf("%d\n", reverse_polish_notation("10 2 3 * - 2 / 8 *"));
}
