#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

#define len 17

int queue();


int main(){
  int north;
  for(int a=1;a<len-1;a+=2){                //행, 열에 평행하게 뽑았는데, 대각선으로 검색해보도록 하자
    for(int b=1;b<len-1;b+=2){
      north = 1 + (a+b-2)%(len-1);          //len-4 =13 -- %최대=12
      printf("%d,%d ",north,b);
    }
    printf("\n");
  }
}
//root_up
if(maze[a-2][b].root==1){
  up.wall=1;
  me.root=1;          //printf("%d",dice);
  root_chain(a,b,maze);
  return 0;
}
if(up.wall==1){
  surround++;
}

//void_up
if(maze[a-2][b].path==1){      //printf("in to%d",dice);
  up.wall=0;
  me.path=1;
  void_chain(a,b,maze);      //void_check(maze);      //wall_check(maze);
  return 0;
}
if(up.wall==1){
  surround++;
}

int next[2][4];
next[0][0]=maze[a-2][b].path;
next[0][1]=maze[a][b+2].path;
next[0][2]=maze[a+2][b].path;
next[0][3]=maze[a][b-2].path;
next[1][0]=maze[a-2][b].root;
next[1][1]=maze[a][b+2].root;
next[1][2]=maze[a+2][b].root;
next[1][3]=maze[a][b-2].root;
int state[2];
state[0]=me.path;
state[1]=me.root;
int wall_dr[4];
wall_dr[0]=up.wall;
wall_dr[1]=right.wall;
wall_dr[2]=down.wall;
wall_dr[3]=left.wall;



//void가 0이고 root가 1이다
//up=0,right=1,down=2,left=3
int connect(int a,int b, int level,int direction,block**maze){
  int next[2][4];
  next[0][0]=maze[a-2][b].path;
  next[0][1]=maze[a][b+2].path;
  next[0][2]=maze[a+2][b].path;
  next[0][3]=maze[a][b-2].path;
  next[1][0]=maze[a-2][b].root;
  next[1][1]=maze[a][b+2].root;
  next[1][2]=maze[a+2][b].root;
  next[1][3]=maze[a][b-2].root;
  int state[2];
  state[0]=me.path;
  state[1]=me.root;
  int wall_dr[4];
  wall_dr[0]=up.wall;
  wall_dr[1]=right.wall;
  wall_dr[2]=down.wall;
  wall_dr[3]=left.wall;
  void (*chain[2])(int,int,block**);
  chain[0]=void_chain(a,b,maze);
  chain[1]=root_chain(a,b,maze);
  //위에 것들은 맨 위 전역변수 위치로 올려버리자
  if(next[level][direction]==1){
    wall_dr[direction]=level;
    state[level]=1;          //printf("%d",dice);
    chain[level](a,b,maze);
    return -1;
  }
  int surround=0;
  if(wall_dr[direction]==1){
    surround++;
  }
  return surround;
}

int root_plus(int a,int b,block**maze){
  int direction,try,surround=0;
  direction=(rand()%4);                    //printf("%d",dice);
  for(int z=0;z<4;z++){
    try=connect(a,b,1,direction,maze);
    if(try==-1){
      return 0;
    }
    else{
      surround+=try;
    }
    switch(direction){
      case 0:{    //up
        direction++;
      }break;
      case 1:{  //right
        direction+=2;
      }break;
      case 2:{  //down
        direction-=2;
      }break;
      case 3:{  //left
        direction--;
      }break;
    }
  }
  if(surround==0){
    switch (direction) {
      case 0:{
        up.wall=1;
      }break;
      case 1:{
        right.wall=1;
      }break;
      case 2:{
        down.wall=1;
      }break;
      case 3:{
        left.wall=1;
      }break;
    }
  }
  return 1;
}

int void_plus(int a,int b,block**maze){   //me.path==1, 상태한테 값주고 그놈 주변 통로 값 재조정
  int dice,surround=0;
  dice=(rand()%4);                    //printf("%d",dice);
  for(int z=0;z<4;z++){
    switch(dice){
      case 0:{    //up
        if(a!=1){      //printf("%d,%d/",a,b);            //printf("%d ",dice);
          if(maze[a-2][b].path==1){      //printf("in to%d",dice);
            up.wall=0;
            me.path=1;
            void_chain(a,b,maze);      //void_check(maze);      //wall_check(maze);
            return 0;
          }
          if(up.wall==1){
            surround++;
          }
        }
        else{
          surround++;
        }
        dice++;
      }break;
      case 1:{  //right
        if(b!=(len-2)){        //printf("%d,%d/",a,b);      //printf("%d ",dice);
          if(maze[a][b+2].path==1){    //printf("in to%d",dice);
            right.wall=0;
            me.path=1;
            void_chain(a,b,maze);    //        void_check(maze);      //      wall_check(maze);
            return 0;
          }
          if(right.wall==1){
            surround++;
          }
        }
        else{
          surround++;
        }
        dice+=2;
      }break;
      case 2:{  //down
        if(a!=(len-2)){      //    printf("%d,%d/",a,b);            //    printf("%d ",dice);
          if(maze[a+2][b].path==1){      //      printf("in to%d",dice);
            down.wall=0;
            me.path=1;
            void_chain(a,b,maze);      //      void_check(maze);      //      wall_check(maze);
            return 0;
          }
          if(down.wall==1){
            surround++;
          }
        }
        else{
          surround++;
        }
        dice-=2;
      }break;
      case 3:{  //left
        if(b!=1){    //      printf("%d,%d/",a,b);    //      printf("%d ",dice);
          if(maze[a][b-2].path==1){    //        printf("in to%d",dice);
            left.wall=0;
            me.path=1;
            void_chain(a,b,maze);      //      void_check(maze);      //      wall_check(maze);
            return 0;
          }
          if(left.wall==1){
            surround++;
          }
        }
        else{
          surround++;
        }
        dice--;
      }break;
    }
  }  //printf("\n");
  if(surround==4){
    int done=1;
    while(done){
      switch (dice) {
        case 0:{
          if(a!=1){
            up.wall=0;
            done--;
          }
          else{
            dice++;
          }
        }break;
        case 1:{
          if(b!=(len-2)){
            right.wall=0;
            done--;
          }
          else{
            dice+=2;
          }
        }break;
        case 2:{
          if(a!=(len-2)){
            down.wall=0;
            done--;
          }
          else{
            dice-=2;
          }
        }break;
        case 3:{
          if(b!=1){
            left.wall=0;
            done--;
          }
          else{
            dice--;
          }
        }break;
      }
    }
  }
  return 1;
}

/*for(int a=1;a<len-1;a+=2){                //행, 열에 평행하게 뽑았는데, 대각선으로 검색해보도록 하자
  for(int b=1;b<len-1;b+=2){
    north = 1 + (a+b-2)%(len-1);          //len-3 =14 -- %최대=13
    if(maze[north][b].path==0){
      not_yet += void_plus(north,b,maze);
    }
  }
}*/
