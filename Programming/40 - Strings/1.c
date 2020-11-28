#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 200
// /home/kirill/UNI/CodeForces/SOLVED/1385.cpp

void a(char* s) {
    int last_slash = strrchr(s, '/') - s;

    for (int i = 0; i < last_slash; i++)
        printf("%c", s[i]);
    printf("\n");
}

void b(char* s) {
    printf("%s\n", strrchr(s, '/')+1);
}

void c(char* s) {
    printf("%s\n", strrchr(s, '.')+1);
}

void d(char* s) {
    int last_slash = strrchr(s, '/') - s;
    int last_dot = strrchr(s, '.') - s;

    for (int i = last_slash+1; i < last_dot; i++)
        printf("%c", s[i]);
    printf("\n");
}

void e(char* s) {
    int last_slash = strrchr(s, '/') - s;
    int second_last_slash = last_slash-1;

    while (s[second_last_slash] != '/' && second_last_slash >= 0)
        second_last_slash--;
    
    for (int i = second_last_slash+1; i < last_slash; i++)
        printf("%c", s[i]);
    printf("\n");
}

void f(char* s) {
    int last_dot = strrchr(s, '.') - s;
    
    for (int i = 0; i < last_dot; i++)
        printf("%c", s[i]);
    printf(".html\n");
}

int main() {
    char s[MAX_SIZE] = {}; scanf("%[^\n]", &s);
    int size = strchr(s, '\0') - s;
    char* str = (char*)malloc((size+1)*sizeof(char));
    strncpy(str, s, size);
    printf("\n");
    
    a(str);
    b(str);
    c(str);
    d(str);
    e(str);
    f(str);
    
    free(str);
    return EXIT_SUCCESS;
}