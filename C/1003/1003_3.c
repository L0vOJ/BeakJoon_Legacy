#include <stdio.h>
int main(){
  int in,a,q,n[41]={0,1};
  int* x;
  scanf("%d",&in);
  x = calloc(in,sizeof(x));
  for(a=0;a<in;a++){
    scanf("%d",&x[a]);
  }
  for(a=2;a<=40;a++){
    n[a] = n[a-2] + n[a-1];
  }
  for(a=0;a<in;a++){
    if(x[a]==0){
      printf("1 0\n");
    }
    else {
      q = x[a];
      printf("%d %d\n",n[q-1],n[q]);
    }
  }
  free(x);
  return 0;
}
