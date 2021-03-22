#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int first;
  int second;
}list;
int main(){
  int n;
  list reserve[100001];
  scanf("%d",&n);
  for(int a=0;a<n;a++){
    scanf("%d %d",reserve[a].first,reserve[a].second);
  }

}
int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;    // 오름차순
}
