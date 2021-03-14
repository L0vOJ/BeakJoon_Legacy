#include<stdio.h>
int main(){
  int in;
  scanf("%d",&in);
  printf("%d",facto(in));
}
int facto(int a){
  if(a<2){
    return 1;
  }
  return a*facto(a-1);
}
