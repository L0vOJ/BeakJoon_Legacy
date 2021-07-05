#include<stdio.h>
int main(){
  int arr[10000];
  int iso[1300];
  int f,l,little=0,output=0;
  for(int a=0;a<10000;a++){
    arr[a]=a+1;
  }
  for(int a=2;a<=100;a++){
    for(int b=2;a*b<10000;b++){
      arr[a*b-1]=0;
    }
  }
  arr[0]=0;
  arr[9999]=0;
  scanf("%d %d",&f,&l);
  for(int ff = f-1;ff<l;ff++){
    if(arr[ff]!=0){
      if(little==0){
        little = arr[ff];
      }
      output +=arr[ff];
    }
  }
  if(little==0){
    printf("-1");
    return 0;
  }
  printf("%d\n%d",output,little);
}
