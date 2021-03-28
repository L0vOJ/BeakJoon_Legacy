#include<stdio.h>
void xy_check(){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      printf("%d,%d ",maze[a][b].x,maze[a][b].y);
    }
    printf("\n");
  }
}
if((a>1 || a<(len-2)) && (b>1 || b<(len-2))){
  if(maze[a-1][b-1].wall==1 && maze[a-2][b].wall==1 && maze[a-1][b+1].wall==1){
    printf("안되냐\n");
    continue;
  }
  else if(maze[a-1][b-1].wall==1 && maze[a][b-2].wall==1 && maze[a+1][b-1].wall==1){
    printf("안되냐\n");
    continue;
  }
  else if(maze[a-1][b+1].wall==1 && maze[a][b+2].wall==1 && maze[a+1][b+1].wall==1){
    printf("안되냐\n");
    continue;
  }
  else if(maze[a+1][b-1].wall==1 && maze[a+2][b].wall==1 && maze[a+1][b+1].wall==1){
    printf("안되냐\n");
    continue;
  }
}

void add_bucket(int a,int b, isolated *island){
  if(island==NULL){
    isolated*island=malloc(sizeof(isolated));
    //island[0].stack=0;
  }
  else{
    int arr_size = sizeof(island)/sizeof(isolated);
    isolated*island = realloc(arr_size+1,sizeof(isolated));
    island[arr_size].stack=arr_size;
  }
  island[stack-1].x=a;
  island[stack-1].y=b;

}
