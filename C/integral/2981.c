#include<stdio.h>
int main(){
  int small,yay;
  int n;
  int arr[101];
  scanf("%d %d",&n,&arr[0]);
  small = arr[0];
  for(int a=1;a<n;a++){
    scanf("%d",&arr[a]);
    if(small>arr[a]){
      small = arr[a];
    }
  }
  arr[0]-=small;
  for(int a=1;a<n;a++){
    arr[a] -= small;
    if(a==1){
      yay = gcd(arr[0],arr[1]);
    }
    else{
      yay = gcd(yay,arr[a]);
    }
  }
  for(int a=2;a<=yay/2;a++){
    if(yay%a==0){
      printf("%d ",a);
    }
  }
  printf("%d",yay);
}
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
