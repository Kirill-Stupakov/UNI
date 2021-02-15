#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bracket_to_num(char c) {
    switch (c) {
        case '.':
            return 0;
            break;
        
        case '(':
            return 1;
            break;        
        case '[':
            return 2;
            break;    
        case '{':
            return 3;
            break;    
        case '<':
            return 4;
            break;

        case ')':
            return -1;
            break;        
        case ']':
            return -2;
            break;    
        case '}':
            return -3;
            break;    
        case '>':
            return -4;
            break;
    }
}

int round(int a) {
    char c; scanf("%d", &c);
    if (c == ')')
        return 1;
    
    return 0;
}

int bracket_check(int current) {
    char c; scanf("%c", &c);
    int br = bracket_to_num(c);

    if (br == 0)
        return 1;
    
    if (br > 0)
        return bracket_check(br);
    
    if (br == -current)
        return 1;
    else
        return 0;
}

int main() {
    printf("%d\n", bracket_check(0));

    return EXIT_SUCCESS;
}