#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n;
    char a;
    scanf("%d%c",&n,&a);
    while (a != '.') {
    if ((a >= 'a') && (a <= 'z')){
        a=a+(n%26);
        printf("%d\n", n%26);'s'
        if (a > 'z') 
            a=((a-'z') + 'a' - 1);
    }
    if ((a >= 'A') && (a <= 'Z')){
        a=a+(n%26);
        if (a > 'Z') 
            a=((a-'Z') + 'A' - 1);
    }
    printf("%c\n",a);
    scanf("%c",&a);
    }
    printf("%c",'.');
    return 0;
}