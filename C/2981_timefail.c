#include<stdio.h>
long long test(int n,int* arr,long long big){
  for(int a=2;a<=big/2;a++){
    int b=0;
    if(big%a==0){
      while(1){
        if(arr[b]%(big/a)){
          break;
        }
        if(b>=n-1){
          return big/a;
        }
        b++;
      }
    }
  }
  return -1;
}
int main(){
  long long small,big=1,block,yay;
  int n;
  int arr[101];
  scanf("%d %d",&n,&arr[0]);
  small = arr[0];
  for(int a=1;a<n;a++){
    scanf("%d",&arr[a]);
    if(small>arr[a]){
      if(big==1){
        big = small;
      }
      small = arr[a];
    }
    if(big<arr[a]){
      big = arr[a];
    }
  }
  for(int a=0;a<n;a++){
    arr[a] -= small;
  }
  yay = test(n,arr,big-small);
  for(int a=2;a<=yay/2;a++){
    if(yay%a==0){
      printf("%d ",a);
    }
  }
  printf("%d",yay);
}
