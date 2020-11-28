#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    char p_name[150], p_adress[150], o_adress[150];
    double cost, part; 
};

struct Base {
    struct Record* nalog;
    int n;
};

void fill(struct Base* a) {
    for (int i=0; i < a->n; i++) {
        printf("# %d\n", i+1);
        
        printf("   p_name: ");
        scanf("%s", &((a->nalog)[i].p_name));

        printf("   p_adress: ");
        scanf("%s", &((a->nalog)[i].p_adress));

        printf("   o_adress: ");
        scanf("%s", &((a->nalog)[i].o_adress));

        printf("   cost: ");
        scanf("%lf", &((a->nalog)[i].cost));

        printf("   part: ");
        scanf("%lf", &((a->nalog)[i].part));

        printf("\n\n");
    }
}

void reg(struct Base* a, char* name, char* newname, char* adr, char* adr_ob) {
    for (int i=0; i<a->n; i++)
        if (!strcmp((a->nalog)[i].p_name, name) && !strcmp((a->nalog)[i].o_adress, adr_ob))
        {
            strcpy((a->nalog)[i].p_name, newname);
            strcpy((a->nalog)[i].p_adress, adr);
        }
}

void demolish(struct Base* a, char* adr_ob){
    int k=0;

    for (int i=0; i<a->n; i++)
        if (strcmp((a->nalog[i].o_adress), adr_ob)) 
            k++;

    struct Record* rec = (struct Record*)malloc(k*sizeof(struct Record));
    
    int N=0;
    for (int i=0; i<a->n; i++)
        if (strcmp((a->nalog[i].o_adress), adr_ob))
            {
                rec[N] = a->nalog[i];
                N++;
            }
    free(a->nalog);
    a->nalog= rec;
    a->n=N;
}

void pay(struct Base* a, char* s, double m){
    FILE* file = fopen(s, "w");
    for (int i=0; i<a->n; i++) {
        double plotinolog = a->nalog[i].cost * a->nalog[i].part * m;
        fprintf(file, "%50s %50s %lf\n", a->nalog[i].p_name, \
        a->nalog[i].p_adress, plotinolog);
    }
    fclose(file);

}

int main (){
    struct Base arr;
    arr.n = 3;
    arr.nalog=(struct Record*)malloc(arr.n*sizeof(struct Record));
    fill(&arr);
    pay(&arr, "tax.txt", 0.5);
}