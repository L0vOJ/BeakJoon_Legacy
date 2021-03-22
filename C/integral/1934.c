#include<stdio.h>
#define big first>last?first:last
int main(){
  int n,first,last,b;
  int arr[1001];
  scanf("%d",&n);
  for(int a=0;a<n;a++){
    scanf("%d %d",&first,&last);
    for(b=big;;b+=big){
      if(b%first==0&&b%last==0){
        break;
      }
    }
    arr[a]=b;
  }
  for(int a=0;a<n;a++){
    printf("%d\n",arr[a]);
  }
}
