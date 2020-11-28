#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


int main() {
    setlocale(LC_ALL, "Russian");

    printf("Size of %s = %d\n", "int", sizeof(int));
    return EXIT_SUCCESS;
}