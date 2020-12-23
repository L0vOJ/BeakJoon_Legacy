#include <stdio.h>
int facto(int n){
  if(n==1){
    return 1;
  }
  else {
    return n*facto(n-1);
  }
}

int main(){
  int a;
  printf("hello?\n");
  scanf("%d",&a);
  int b = a/3;
  printf("%d",b);
}
