#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long euler_function(int n) {
    unsigned long long ans = n;

    for (int i = 2; n != 1; i++)
        if (n%i == 0) {
            ans *= i-1;
            ans /= i;
            while (n%i == 0)
                n /= i;
        }

    return ans;
}

int main() {
    int n; scanf("%d", &n);
    printf("%d", euler_function(n));

    return EXIT_SUCCESS;
}