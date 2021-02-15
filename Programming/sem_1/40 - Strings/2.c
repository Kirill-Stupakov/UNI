#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 200

int main() {
    char s1[MAX_SIZE] = {}; scanf("%s", &s1);
    char s2[MAX_SIZE] = {}; scanf("%s", &s2);

    int ans = 0;
    int last = 0;
    while (strstr(s1+last, s2) != NULL) {
        last = strstr(s1+last, s2) - s1 + 1;
        ans++;
    }

    printf("%d\n", ans);
    return EXIT_SUCCESS;
}