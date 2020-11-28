#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Computer {
    char processor_type[80];
    double frequency;
    int cores;

    char motherboard_type[80];
    int ram_capacity;
    int hdd_capacity;

    double dvd_speed;
};

struct Computer_store {
    struct Computer* store;
    int size;
};

void fill(struct Computer_store* a) {
    for (int i = 0; i < a->size; i++) {
        printf("Computer #%d:\n", i+1);

        printf("   Processor type: ");
        scanf("%s", &((a->store)[i].processor_type));

        printf("   Processor frequency: ");
        scanf("%lf", &((a->store)[i].frequency));

        printf("   Number of cores: ");
        scanf("%d", &((a->store)[i].cores));

        printf("   Motherboard type: ");
        scanf("%s", &((a->store)[i].motherboard_type));

        printf("   RAM capacity: ");
        scanf("%d", &((a->store)[i].ram_capacity));

        printf("   HDD capacity: ");
        scanf("%d", &((a->store)[i].hdd_capacity));

        printf("   DVD-RW speed: ");
        scanf("%lf", &((a->store)[i].dvd_speed));

        printf("\n\n");
    }
}

void delete(struct Computer_store* a) {
    int new_size = 0;

    for (int i = 0; i < a->size; i++)
        if ((a->store)[i].ram_capacity >= 2)
            new_size++;
    
    struct Computer* new_store = (struct Computer*)malloc(new_size*sizeof(struct Computer));

    int t = 0;
    for (int i = 0; i < a->size; i++)
        if ((a->store)[i].ram_capacity >= 2) {
            new_store[t] = (a->store)[i];
            t++;
        }
    free(a->store);
    
    a->store = new_store;
    a->size = new_size;
}

void write_file(struct Computer_store* a, char* filename) {
    FILE* f = fopen(filename, "w");

    //fprintf(f, "PROCESSOR\t\tFREQUENCY\t\tCORES\t\tMOTHERBOARD\t\tRAM\t\tHDD\t\tDVD\n");

    for (int i = 0; i < a->size; i++)
        if ((a->store)[i].cores == 4) {
            fprintf(f, "%s\t\t%.2lf\t\t%d\t\t%s\t\t%d\t\t%d\t\t%.2lf\n", \
            (a->store)[i].processor_type, (a->store)[i].frequency, \
            (a->store)[i].cores, (a->store)[i].motherboard_type, \
            (a->store)[i].ram_capacity, (a->store)[i].hdd_capacity, \
            (a->store)[i].dvd_speed);
    }
}

int main() {
    int size = 3;

    struct Computer_store a;
    a.store = (struct Computer*)malloc(size*sizeof(struct Computer));
    a.size = size;
    
    fill(&a);
    delete(&a);
    write_file(&a, "table.txt");

    return EXIT_SUCCESS;
}