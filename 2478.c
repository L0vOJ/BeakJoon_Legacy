#include<stdio.h>
long long fib(long long a,long long b,int count){
  long long c = a+b;
  if(count ==1){
    return c;
  }
  return fib(b,c,count-1);
}
int main(){
  int n;
  scanf("%d",&n);
  switch (n) {
    case 1:
    case 2:
      printf("1");
    break;
    default:
      printf("%lld",fib(1,1,n-2));
    break;
  }
}
