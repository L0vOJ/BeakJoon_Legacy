#include<stdio.h>
int main(){
  int arr[200000];
  int a,f,l;
  for(a=0;;a++){
    scanf("%d %d",&f,&l);
    if(f==0&&l==0){
      break;
    }
    arr[a]=f+l;
  }
  for(int b=0;b<a;b++){
    printf("%d\n",arr[b]);
  }
}
