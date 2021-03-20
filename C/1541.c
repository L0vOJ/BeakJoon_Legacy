#include<stdio.h>
int main(){
  char arr[60];
  int num_buffer=0;
  int calc_buffer=0;
  int output=0;
  scanf("%s",arr);
  for(int a=0;a<60;a++){
    if(arr[a] >= 48 && arr[a] < 58){
      num_buffer *=10;
      num_buffer += (arr[a]-48);
    }
    else if(arr[a] == 0){
      if(calc_buffer == 1){
        output -= num_buffer;
      }
      else{
        output += num_buffer;
      }
      break;
    }
    else{
      if(calc_buffer == 0){
        output += num_buffer;
        if(arr[a] == '-'){
          calc_buffer = 1;
        }
      }
      else{
        output -= num_buffer;
      }
      num_buffer = 0;
    }
  }
  printf("%d",output);
}
