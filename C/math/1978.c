#include<stdio.h>
int main(){
  int arr[1000];
  int iso[170];
  int n,say,output=0;
  int f,l,little=0;
  for(int a=0;a<1000;a++){
    arr[a]=a;
  }
  for(int a=2;a<=33;a++){
    for(int b=2;a*b<1000;b++){
      arr[a*b]=0;
    }
  }
  arr[1]=0;
  scanf("%d",&n);
  for(int a=0;a<n;a++){
    scanf("%d",&say);
    if(say==1000){
      continue;
    }
    if(arr[say]!=0){
      output++;
    }
  }
  printf("%d",output);
}
