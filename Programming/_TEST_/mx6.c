#include <stdio.h>
#include <stdlib.h>

int check_func(int a1, int a2, int b, int x, int y)
{
    return ((a1&x)^(a2&y)==b);
}
int main (void)
{
    unsigned int x11, x12, x21, x22, y1, y2, resx=0, resy=0, check=1;
    int a11[32]={0}, a12[32]={0};
    int xi=0, yi=0;
    int a21[32]={0}, a22[32]={0};
    int b1[32]={0}, b2[32]={0};
    int x[32]={0}, y[32]={0};
    scanf("%u %u",&x11, &x12);
    scanf("%u %u",&x21, &x22);
    scanf("%u %u",&y1, &y2);
    for (int i=0; i<32; i++){
        a11[i]=x11%2;
        a12[i]=x12%2;
        a21[i]=x21%2;
        a22[i]=x22%2;
        b1[i]=y1%2;
        b2[i]=y2%2;
        x11=x11/2;
        x12=x12/2;
        x21=x21/2;
        x22=x22/2;
        y1=y1/2;
        y2=y2/2;
    for (int i=0; i<32; i++) {
        for (int j=0; j<4; j++){
            if (i==0){
                xi=0;
                yi=0;
            }
            if (i==1){
                xi=0;
                yi=1;
            }
            if (i==2){
                xi=1;
                yi=0;
            }
            if (i==3){
                xi=1;
                yi=1;
            }
            if ((check_func(a11[i],a12[i],b1[i],xi,yi))==(check_func(a21[i],a22[i],b2[i],xi,yi))) {
                x[i]=x;
                y[i]=y;
            }   
            else check=0;
        }

    }
    for (int i=31; i>=0; i--){
        resx=resx*2+x[i];
        resy=resy*2+y[i];
    }
    if (check==0)
        printf("No\n");
    else {
        printf("Yes\n");
        printf("%u %u",resx,resy);
    }
    return 0;
}