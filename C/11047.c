#include<stdio.h>
int main(){
  int arr_num,input,output=0;
  int arr[10];
  scanf("%d %d",&arr_num,&input);
  for(int a=0;a<arr_num;a++){
    scanf("%d",&arr[a]);
  }
  while(input>0){
    for(int a=arr_num-1;a>=0;a--){
      while(input>=arr[a]){
        input-=arr[a];
        output++;
      }
    }
  }
  printf("%d",output);
}
