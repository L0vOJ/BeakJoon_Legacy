#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define choco_up (choco_list[a][1] + choco_list[a][3])
#define choco_down (choco_list[a][0] + choco_list[a][2])
#define choco_area (choco_list[a][2] * choco_list[a][3])

#define upline

#define in_the_area (
  choco_up <= h/w*choco_list[a][0] && choco_down >=
)




void choco_init(int n,int** choco_list){
  choco_list = calloc(n,sizeof(int));
  for(int a=0;a<4;a++){
    choco_list[a] = calloc(4,sizeof(int));
  }
}

int main(){
  int w,h,l,n;
  int choco_in;
  int** choco_list;
  scanf("%d %d %d %d",&w,&h,&l,&n);
  choco_init(n,choco_list);
  for(int a=0;a<n;a++){
    for(int b=0;b<4;b++){
      scanf("%d",&choco_in);
      choco_list[a][b] = choco_in;
    }
  }
  for(int c=0;c<=l;c++){
    for(int a=0;a<n;a++){

    }
  }
}
