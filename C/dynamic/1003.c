#include <stdio.h>
int main(){
  int in,a,q,n[41]={0,1};
  scanf("%d",&in);
  for(a=2;a<=40;a++){
    n[a] = n[a-2] + n[a-1];
  }
  for(a=0;a<in;a++){
    scanf("%d",&q);
    if(q==0){
      printf("1 0\n");
    }
    else {
      printf("%d %d\n",n[q-1],n[q]);
    }
  }
  return 0;
}
