#include <stdio.h>
int main(){
  int a,b,c;
  scanf("%d",&a);
  scanf("%d",&b);
  c = b%10;
  printf("%d\n%d\n%d\n%d\n",a*c,a*((b%100)-c)/10,a*(b/100),a*b);
}

//나머지를 통해 각 값을 구하는 것이 핵심
//%10, %100으로 구한다
