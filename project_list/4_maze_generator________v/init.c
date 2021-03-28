#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>
#define len 9

typedef struct{
  int x;
  int y;
  int wall;
  int root;
  int stuck;
}block;

int main(){
  block** maze;   //**maze=���� *maze ������ maze ����������
  maze=calloc(len,sizeof(block));
  for(int a=0;a<len;a++){
    *(maze+a)=calloc(len,sizeof(block));
  }
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      maze[a][b].x=a;
      maze[a][b].y=b;
    }
  }
  for(int a=0;a<len;a++){
    maze[0][a].wall=1;
    maze[a][0].wall=1;
    maze[len-1][a].wall=1;
    maze[a][len-1].wall=1;
  }
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(maze[a][b].wall==1){
        printf("@");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  free(maze);
}
