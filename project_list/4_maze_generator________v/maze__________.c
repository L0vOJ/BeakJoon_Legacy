#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>
#define len 105  //무조건 홀수여야만 한다  4의배수 +1의 값만 가능하다

#define up maze[a-1][b]
#define down maze[a+1][b]
#define left maze[a][b-1]
#define right maze[a][b+1]
#define me maze[a][b]

#define ct_wall_len ((len-3)/2) //내부 고정벽 1열 개수
#define ct_void_len ((len-1)/2) //내부 고정공간 1열 개수

typedef struct{
  int x;
  int y;
  int wall;
  int root;
  int path;
}block;

void block_build(block**);

void wall_check(block**maze);
void root_check(block**maze);
void void_check(block**maze);

block** block_init();
void rand_wall(block**maze);

void root_link(block**maze);
void root_pruning(block**maze);
int root_plus(int a,int b,block**maze);
void root_chain(int a,int b,block**maze);

void void_seed(block** maze);
void void_pruning(block**maze);
int void_plus(int a,int b,block**maze);
void void_chain(int a,int b,block**maze);

//--------------------------------------------
int main(){
  block**maze=block_init();
  block_build(maze);
  wall_check(maze);
}

void block_build(block**maze){
  rand_wall(maze);

  root_link(maze);      //외부벽으로부터 시작
  root_pruning(maze);//  wall_check(maze);
  printf("1");            //주의! 건들지 말것 이 프로그램의 영혼이 담김

  void_seed(maze);      //빈 공간의 중심에서부터 시작
  void_pruning(maze);//  wall_check(maze);
  printf("2\n");          //빼면 root작업과 void 작업이 무시당한다 왜인지는 모르겠지만
  maze[1][0].wall=0;
  maze[len-2][len-1].wall=0;        //중단:a부분에 (len-3)/2 상단:1 하단:len-2
}
//-------------------------------
block** block_init(){
  block** maze;   //**maze=변수 *maze 포인터 maze 이중포인터
  maze=calloc(len,sizeof(block));
  for(int a=0;a<len;a++){
    *(maze+a)=calloc(len,sizeof(block));
  }
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      me.x=a;
      me.y=b;
    }
  }
  for(int a=0;a<len;a++){
    maze[0][a].wall=1;
    maze[a][0].wall=1;
    maze[len-1][a].wall=1;
    maze[a][len-1].wall=1;
  }
  //maze[1][0].wall=0;
  //maze[len-2][len-1].wall=0;

  for(int a=0;a<len;a+=2){
    for(int b=0;b<len;b+=2){
      me.wall=1;
    }
  }
  return maze;
}

void rand_wall(block**maze){  //if len=17
  srand(time(0));
  int a,b,tap=0;
  while(1){
    a=(1+rand()%(len-2));             //a:1~15
    if(a%2){                          //a가 홀수라면
      b=2*(1+rand()%(ct_wall_len));     //b:2,4,6...14 //총 7개
    }
    else{
      b=1+2*(rand()%(ct_void_len));          //b:1,3,5...15 //총 8개
    }
    if(me.wall==0){         //신규 설치일때
      tap++;
    }
    me.wall=1;
    if(tap>=(pow(len,2)-pow(ct_void_len,2)-pow(ct_wall_len,2))/3){
      break;
    }
  }
}

void root_link(block**maze){
  for(int a=0;a<len;a+=2){
    maze[0][a].root=1;
    maze[a][0].root=1;
    maze[len-1][a].root=1;
    maze[a][len-1].root=1;
  }
  for(int a=2;a<len-1;a+=2){
    if(maze[1][a].wall==1){
      maze[2][a].root=1;
      root_chain(2,a,maze);
    }
    if(maze[len-2][a].wall==1){
      maze[len-3][a].root=1;
      root_chain(len-3,a,maze);
    }
    if(maze[a][1].wall==1){
      maze[a][2].root=1;
      root_chain(a,2,maze);
    }
    if(maze[a][len-2].wall==1){
      maze[a][len-3].root=1;
      root_chain(a,len-3,maze);
    }
  }
}

void root_pruning(block**maze){
  srand(time(0));
  int not_yet;
  int north;
  while(not_yet){
    not_yet=0;
    for(int a=2;a<len-2;a+=2){                //행, 열에 평행하게 뽑았는데, 대각선으로 검색해보도록 하자
      for(int b=2;b<len-2;b+=2){
        north = 2 + (a+b-4)%(len-3);          //len-3 =14 -- %최대=13
        if(maze[north][b].root==0){
          not_yet += root_plus(north,b,maze);
        }
      }
    }       //주석처리는 여기
  }
}

int root_plus(int a,int b,block**maze){
  int dice,surround=0;
  dice=(rand()%4);                    //printf("%d",dice);
  for(int z=0;z<4;z++){
    switch(dice){
      case 0:{    //up
        if(maze[a-2][b].root==1){
          up.wall=1;
          me.root=1;          //printf("%d",dice);
          root_chain(a,b,maze);
          return 0;
        }
        if(up.wall==1){
          surround++;
        }
        dice++;
      }break;
      case 1:{  //right
        if(maze[a][b+2].root==1){
          right.wall=1;
          me.root=1;          //printf("%d",dice);
          root_chain(a,b,maze);
          return 0;
        }
        if(right.wall==1){
          surround++;
        }
        dice+=2;
      }break;
      case 2:{  //down
        if(maze[a+2][b].root==1){
          down.wall=1;
          me.root=1;          //printf("%d",dice);
          root_chain(a,b,maze);
          return 0;
        }
        if(down.wall==1){
          surround++;
        }
        dice-=2;
      }break;
      case 3:{  //left
        if(maze[a][b-2].root==1){
          left.wall=1;
          me.root=1;          //printf("%d",dice);
          root_chain(a,b,maze);
          return 0;
        }
        if(left.wall==1){
          surround++;
        }
        dice--;
      }break;
    }
  }
  if(surround==0){
    switch (dice) {
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

void root_chain(int a,int b,block**maze){
  if(up.wall==1){
    if(maze[a-2][b].root==0){
      maze[a-2][b].root=1;
      root_chain(a-2,b,maze);
    }
  }
  if(right.wall==1){
    if(maze[a][b+2].root==0){
      maze[a][b+2].root=1;
      root_chain(a,b+2,maze);
    }
  }
  if(down.wall==1){
    if(maze[a+2][b].root==0){
      maze[a+2][b].root=1;
      root_chain(a+2,b,maze);
    }
  }
  if(left.wall==1){
    if(maze[a][b-2].root==0){
      maze[a][b-2].root=1;
      root_chain(a,b-2,maze);
    }
  }
  return;
}

void void_seed(block** maze){
  maze[(len-3)/2][(len-3)/2].path=1;
  void_chain((len-3)/2,(len-3)/2,maze);
}

void void_pruning(block**maze){
  srand(time(0));
  int not_yet;
  int north;
  while(not_yet){
    not_yet=0;
    for(int a=3;a<len+1;a+=2){                //행, 열에 평행하게 뽑았는데, 대각선으로 검색해보도록 하자
      for(int b=len-2;b>0;b-=2){
        north = 1 + (a+b-2)%(len-1);          //len-3 =14 -- %최대=13
        if(maze[north][b].path==0){
          not_yet += void_plus(north,b,maze);
        }
      }                       //이번엔 [3][3]이 지 멋대로 path값을 가짐 어떻게 처리좀
    }       //주석처리는 여기  //관계연산자 ==라고 쳐야되는데 =라고 쳐서 case=1 구멍 뚤린거 메꿈
  }  //printf("끝났냐?\n");   //maze[-1] 이런거 건들여서 터지는거임 빨리 방법 생각좀 //처리해드렸습니다^^
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


void void_chain(int a,int b,block**maze){
  if(up.wall==0){
    if(maze[a-2][b].path==0){
      maze[a-2][b].path=1;
      void_chain(a-2,b,maze);
    }
  }
  if(right.wall==0){
    if(maze[a][b+2].path==0){
      maze[a][b+2].path=1;
      void_chain(a,b+2,maze);
    }
  }
  if(down.wall==0){
    if(maze[a+2][b].path==0){
      maze[a+2][b].path=1;
      void_chain(a+2,b,maze);
    }
  }
  if(left.wall==0){
    if(maze[a][b-2].path==0){
      maze[a][b-2].path=1;
      void_chain(a,b-2,maze);
    }
  }
  return;
}

void wall_check(block**maze){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.wall){
        printf("■");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}

void root_check(block**maze){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.root){
        printf("■");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
void void_check(block**maze){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.path){
        printf("■");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
