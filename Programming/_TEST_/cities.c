#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int city(char** names, char* left, char* current, int length) {
    int found = 0;

    for (int i = 0; i < 10; i++)
        if (left[i] && names[i][0] == current[strlen(current)-1])
            found = 1;

    if (!found)
        return length;

    int ans = 0;
    for (int i = 0; i < 10; i++)
        if (left[i] && names[i][0] == current[strlen(current)-1]) {
            left[i] = 0;
            ans += city(names, left, names[i], length+1);
            left[i] = 1;
        }
    
    return ans;
}