#include<stdio.h>
#include<math.h>
void front_shift();
void back_shift();
void array_check();
int main()
{
  while(1){
    printf("1.front_shift\n2.back_shift\n");
    int want;
    printf("-------------\n");
    scanf("%d",&want);
    switch(want){
      case 1:
      front_shift();
      break;

      case 2:
      back_shift();
      break;

      case 3:
      array_check();
      break;

      default:
      printf("잘못된 입력값 다시 써라\n");
      break;
    }
  }
}
void front_shift(){ //<--
  int arr[41]={1,2,3,4,5,6,7,8,9};
  int run=1;
  while(arr[run]!='\0'){
    arr[run-1] = arr[run];
    run++;
  }
  for(int a=0;a<10;a++){
    printf("%d",arr[a]);
  }
  printf("\n------------------\n");
}
void back_shift(){  //-->
  int arr[41]={1,2,3,4,5,6,7,8,9};
  int run=10;
  while(run >0){
    arr[run]=arr[run-1];
    run--;
  }
  for(int a=0;a<10;a++){
    printf("%d",arr[a]);
  }
  printf("\n--------------------\n");
}
void array_check() {
  int arr[41]={0};
  for(int a=0;a<10;a++){
    printf("%d",arr[a]);
  }
  printf("\n");
}
