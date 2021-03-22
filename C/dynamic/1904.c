#include<stdio.h>
int main(){
  int in,t;
  int* p;
  scanf("%d",&in);
  p=calloc(in,sizeof(p));
  if(in==1){
    printf("1\n");
  }
  else if(in==2){
    printf("2\n");
  }
  else{
    p[0] = 1;
    p[1] = 2;
    for(int a=2;a<in;a++){
      p[a] = (p[a-2] + p[a-1]) % 15746;
    }
    printf("%d",(p[in-1]));
  }
  return 0;
}
