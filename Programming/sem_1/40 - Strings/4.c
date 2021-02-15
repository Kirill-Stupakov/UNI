#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200

int main() {
    char s[MAX_SIZE] = {}; scanf("%s", &s);
    int ans = 0;

    for (int i = 0; i < MAX_SIZE-1; i++) {
        if (isdigit(s[i]) && !isdigit(s[i+1]))
            ans++;
    }

    printf("%d\n", ans);
    return EXIT_SUCCESS;
}