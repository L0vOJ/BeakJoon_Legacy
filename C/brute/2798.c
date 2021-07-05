#include<stdio.h>
#define sum arr[a]+arr[b]+arr[c]
int main(){
  int n,m,small,output=0;
  int arr[101];
  scanf("%d %d",&n,&m);
  for(int a=0;a<n;a++){
    scanf("%d",&arr[a]);
  }
  for(int a=0;a<n;a++){
    for(int b=a+1;b<n;b++){
      for(int c=b+1;c<n;c++){
        if(sum<=m){
          if(output < sum){
            output = sum;
          }
        }
      }
    }
  }
  printf("%d",output);
}
