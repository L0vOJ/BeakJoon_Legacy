#include<stdio.h>
int main(){
  int in;
  scanf("%d",&in);
  printf("%d",facto(in));
}
int facto(int a){
  if(a==0){
    return 0;
  }
  else if(a==1){
    return 1;
  }
  return a*facto(a-1);
}
