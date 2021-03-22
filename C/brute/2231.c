#include<stdio.h>
#include<math.h>
int main(){
  int n,output=0;
  scanf("%d",&n);
  for(int a=n-100*(int)log10((double)n);a<n;a++){
    int buffer=a;
    for(int b=1;b<=n;b*=10){
      buffer += (a%(10*b))/b;
    }
    if(buffer == n){
      printf("%d",a);
      return 0;
    }
  }
  printf("0");
}
