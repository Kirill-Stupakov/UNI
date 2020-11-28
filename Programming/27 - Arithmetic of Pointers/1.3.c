#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define size 5

float* average(float* p[size]) {
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += (int)(p[i]);

    sum /= size;

    int offset = (sum-(int)p[0]) % sizeof(float);     //subtract from sum
    if (offset < 0)
        offset += sizeof(float);
    
    if (offset) {
        if (offset < sizeof(float)/2)
            sum -= offset;
        else
            sum += sizeof(float)-offset;
    }

    float* res = (float*)sum;
    return res;
}   

int main() {
    srand(time(NULL));

    float arr[10];
    for (int i = 0; i < 10; i++)
        arr[i] = i;
    float* p[size];

    for (int i = 0; i < size; i++) {
        int ind; scanf("%d", &ind);
        p[i] = arr+ind;
    }

    float* res = average(p);

    printf("%f", *res);
    return EXIT_SUCCESS;
}