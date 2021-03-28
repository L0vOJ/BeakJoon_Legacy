#include<stdio.h>
int main(){
  int arr[15]={0,1,2,3,4,5,6,7,8,9,0};
  int ns[15]={0};
  printf("%d\n",*arr);
  printf("%d\n",*arr+1);
  for(int z=0;z<9;z++){
    printf("%d/",arr[z]);
  }
  printf("\n");
  for(int a=0;a<9;a++){
    printf("%d",*(arr+a));
    ns[a]=*(arr+a);    //sizeof(int)=4 <--아무 상관 없다아
  }
  printf("\n");
  for(int b=0;b<9;b++){
    printf("%d/",ns[b]);
  }
}
