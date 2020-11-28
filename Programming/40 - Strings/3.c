#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 200

int main() {
    char s[MAX_SIZE] = {}; scanf("%s", &s);
    char from[MAX_SIZE] = {}; scanf("%s", &from);
    char to[MAX_SIZE] = {}; scanf("%s", &to);


    for (int i = 0; i < MAX_SIZE; i++)
        for (int j = 0; j < MAX_SIZE ; j++)
            if (s[i] == from[j]) {
                s[i] = to[j];
                break;
            }

    printf("%s\n", s);
    return EXIT_SUCCESS;
}