#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10

struct Car {
    char is_available;
    int price;
    char color[30];
    double engine_rpm;
};

void initialize(struct Car* a, int size) {
    for (int i = 0; i < size; i++)
        a[i].is_available = 0;
}

void fill(struct Car* a, int size) {
    for (int i = 0; i < size; i++)
        if (!a[i].is_available) {
            a[i].is_available = 1;
            printf("Car %2d:\n", i);
            
            printf("\tPrice:      ");
            scanf("%d", &a[i].price);

            printf("\tColor:      ");
            scanf("\n%[^\n]", &a[i].color);

            printf("\tEngine RPM: ");
            scanf("%lf", &a[i].engine_rpm);

            system("clear");
        }
}

void display(struct Car* a, int size) {
    for (int i = 0; i < size; i++)
        if (a[i].is_available) {
            printf("Car %2d:\n", i);
            
            printf("\tPrice:      %d\n", a[i].price);
            printf("\tColor:      %s\n", a[i].color);
            printf("\tEngine RPM: %lf\n", a[i].engine_rpm);

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
    printf("Press Enter to continue: ");
    scanf("\n");
}

void sell(struct Car* a, int size) {
    int n; scanf("%d", &n);

    if ((n < size) && (a[n].is_available)) {
        a[n].is_available = 0;
        printf("Sold!\n");
    }
    else
        printf("Error: this car is not for sale!\n");
    
    printf("Press Enter to continue: ");
    scanf("\n");
}

int main() {
    struct Car a[SIZE];

    int choice = 0;
    void (*f[])(struct Car*, int) = {initialize, fill, display, sell};

    while (choice != 5) {
        system("clear");
        printf("-=-=-=-=-=-= | CarShop v0.1 | =-=-=-=-=-=-\n");
        printf("Choose your option:\n");
        printf("  1: Initialize\n");
        printf("  2: Fill\n");
        printf("  3: Display\n");
        printf("  4: Sell\n");
        printf("  5: Exit\n");

        scanf("%d", &choice);
        while (choice < 1 || choice > 5) {
            printf("Error: invalid option. Try again: ");
            scanf("%d", &choice);
        }

        system("clear");
        if (choice == 5)
            break;
        f[choice-1](a, SIZE);
    }


    return EXIT_SUCCESS;
}