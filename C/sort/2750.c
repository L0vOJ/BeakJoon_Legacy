#include <stdio.h>
#include <stdlib.h>
int main(){
  int* arr;
  int buffer,in,trigger=1;
  scanf("%d",&in);
  arr = calloc(in,sizeof(int));
  for(int a=0;a<in;a++){
    scanf("%d",&arr[a]);
  }
  while(trigger){
    trigger = 0;
    for(int a=0;a<in-1;a++){
      if(arr[a] > arr[a+1]){
        buffer = arr[a];
        arr[a] = arr[a+1];
        arr[a+1] = buffer;
        trigger = 1;
      }
    }
  }
  for(int a=0;a<in;a++){
    printf("%d\n",arr[a]);
  }
  return 0;
}
