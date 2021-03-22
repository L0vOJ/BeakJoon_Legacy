#include<stdio.h>
int main(){
  int arr[200000];
  int n,f,l;
  scanf("%d",&n);
  for(int a=0;a<n;a++){
    scanf("%d %d",&f,&l);
    arr[a] = f+l;
  }
  for(int a=0;a<n;a++){
    printf("%d\n",arr[a]);
  }
}
