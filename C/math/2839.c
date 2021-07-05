#include<stdio.h>
int main(){
  int in;
  scanf("%d",&in);
  printf("%d\n",calc(in));
}
int calc(int n){
  int count = 0;
  while(n % 5 != 0){
    n-=3;
    count++;
    if(n<0){
      return -1;
    }
  }
  count += n/5;
  return count;
}
