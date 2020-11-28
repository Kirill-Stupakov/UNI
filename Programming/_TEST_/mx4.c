#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(void) {
  float x1,y1,x2,y2,x3,y3;
  float mx1,my1,mx,my;
  scanf("%f %f",&x1,&y1);
  scanf("%f %f",&x2,&y2);
  scanf("%f %f",&x3,&y3);
  mx1=(x1+x2)*0.5;
  my1=(y1+y2)*0.5;
  if (x3>mx1){
    mx=(x3-mx1)*(1/3)+mx1;
    my=fabs(y3-my1)*(1/3)+min(my1,y3);
  }
  else {
    mx=(mx1-x3)*(2/3)+x3;
    my=fabs(y3-my1)*(2/3)+min(my1,y3);
  }
  printf("%.4f %.4f",mx,my);
  return 0;
}