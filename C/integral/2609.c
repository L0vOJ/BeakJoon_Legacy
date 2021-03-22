#include<stdio.h>
#define big first>last?first:last
int main(){
  int first,last,a;
  scanf("%d %d",&first,&last);
  for(a=big;;a--){
    if(first%a==0 && last%a==0){
      break;
    }
  }
  printf("%d\n",a);
  for(a=big;;a+=big){
    if(a%first==0 && a%last==0){
      break;
    }
  }
  printf("%d",a);
}
