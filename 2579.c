#include<stdio.h>
int main(){
  int arr[301][3];
  int n,score;
  scanf("%d",&n);
  for(int z=0;z<3;z++){
    arr[0][z]=0;
  }
  for(int a=1;a<=n;a++){
    printf("\n-------------\n");
    scanf("%d",&score);
    arr[a][0] = arr[a-1][1]>arr[a-1][2]?arr[a-1][1]:arr[a-1][2];
    arr[a][1] = arr[a-1][0]+score;
    arr[a][2] = arr[a-1][1]+score;
    for(int z=0;z<3;z++){
      printf("%d ",arr[a][z]);
    }
  }
  printf("\n------%d-------",arr[n][1]>arr[n][2]?arr[n][1]:arr[n][2]);
}
