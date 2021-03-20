#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;    // 오름차순
}
int main(){
  int arr_num,output=0;
  int arr[1000];
  scanf("%d",&arr_num);
  for(int a=0;a<arr_num;a++){
    scanf("%d",&arr[a]);
  }
  qsort(arr,arr_num,4,compare);
  for(int a=0;a<arr_num;a++){
    output += arr[a]*(arr_num-a);
  }
  printf("%d",output);
}
