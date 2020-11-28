#include <stdio.h>
int main() { int offset; char c; char fl[] = {'A', 'a'}; scanf("%d%c", &offset, &c);
    while (c != '.') { if (c != ' ') c = (c - fl[c >= 'a'] + offset) % 26 + fl[c >= 'a'];
    printf("%c", c); scanf("%c", &c); } printf(".\n"); return 0; }
