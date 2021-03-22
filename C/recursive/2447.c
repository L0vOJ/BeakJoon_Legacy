#include<stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  for(int a=1;a<=n;a++){
    for(int b=1;b<=n;b++){
      disicion(n,a,b);
    }
    printf("\n");
  }
  return 0;
}
int disicion(int n,int a,int b){
  if(n/3 < a && a <= n/3*2 && n/3 < b && b <= n/3*2){
    printf(" ");
  }
  else if(n==1){
    printf("*");
  }
  else disicion(n/3,a%(n/3),b%(n/3));
}
