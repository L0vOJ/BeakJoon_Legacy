#include <stdio.h>
int main(){
  int a,b,v,q;
  scanf("%d %d %d",&a,&b,&v);
  q = (v-b)/(a-b);
  if((v-b)%(a-b) != 0){
    q++;
  }
  printf("%d",q);
  return 0;
}
