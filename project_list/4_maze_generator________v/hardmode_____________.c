#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

#define len 53  //무조건 홀수여야만 한다  4의배수 +1의 값만 가능하다

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
  int cline;
}block;

void block_clear(block**maze);
void block_build(block**);

void wall_check(block**maze);
void root_check(block**maze);
void void_check(block**maze);

block** block_init();
void rand_wall(block**maze);

void root_link(block**maze);
void root_pruning(block**maze);
int root_plus(int a,int b,block**maze);
int root_chain(int a,int b,block**maze);

void void_seed(block** maze);
void void_pruning(block**maze);
int void_plus(int a,int b,block**maze);
int void_chain(int a,int b,block**maze);

void solution(block**maze);
void path_clear(block**maze);
void path_search(int a,int b,block**maze);
void path_find(int a,int b,block**maze);

void cline_check(block**maze);
void path_check(block**maze);
void solution_check(block**maze);

void door_push(block**maze);
int turn(int direction);
int connection(int a,int b, int level,int direction,block**maze);

block** operate(int want,block**maze);
void back_to_startline();
//--------------------------------------------
int level=1;
int hard=0;
int main(){
  int want;
  block**maze=block_init();
  block_build(maze);
  door_push(maze);
  while(1){
    printf("~~maze generator and path finder~~\n");
    printf("미로 원본을 출력하고싶다면 1번을, 미로의 해답을 찾고싶다면 2번을, 미로를 초기화하려면 3번을 입럭하세요\n");
    printf("※임시:미로의 난이도를 조절하고 싶다면 4번을 입력해주십시오");
    scanf("%d",&want);
    maze=operate(want,maze);
    back_to_startline();
  }
}

block** operate(int want,block**maze){
  switch(want){
    case 1:{
      wall_check(maze);
    }break;
    case 2:{
    if(level==1){
      while(1){
        solution(maze);
        if(maze[len-2][len-2].path>=80){
          break;
        }
        else if(hard==0){
          break;
        }
        printf("waiting...\r");
        operate(3,maze);
      }
      level=2;
    }
    solution_check(maze);
    printf("출구까지의 거리는 %d\n",maze[len-2][len-2].path);
    }break;
    case 3:{
      block_clear(maze);
      block_build(maze);
      level=1;
      //printf("초기화 완료!\n");
    }break;
    case 4:{
      if(hard){
        hard=0;
        printf("hardmode off\n");
      }
      else{
        hard=1;
        printf("hardmode on\n");
      }
    }break;
  }
  return maze;
}
void block_clear(block**maze){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      me.wall=0;
      me.root=0;
      me.path=0;
      me.cline=0;
    }
  }
  for(int a=0;a<len;a+=2){
    for(int b=0;b<len;b+=2){
      me.wall=1;
    }
  }
}
void block_build(block**maze){
  rand_wall(maze);

  root_link(maze);      //외부벽으로부터 시작
  root_pruning(maze);//  wall_check(maze);
  printf(" ");            //주의! 건들지 말것 이 프로그램의 영혼이 담김

  void_seed(maze);      //빈 공간의 중심에서부터 시작
  void_pruning(maze);//  wall_check(maze);
  printf(" \r");          //빼면 root작업과 void 작업이 무시당한다 왜인지는 모르겠지만
      //중단:a부분에 (len-3)/2 상단:1 하단:len-2
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
  int direction,try,surround=0;
  direction=(rand()%4);                    //printf("%d",direction);
  for(int z=0;z<4;z++){
    try=connection(a,b,1,direction,maze);
    if(try==-1){
      return 0;
    }
    else{
      surround+=try;
    }
    direction = turn(direction);
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

int root_chain(int a,int b,block**maze){
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
  return 0;
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
  int direction,try,surround=0;
  direction=(rand()%4);                    //printf("%d",direction);
  for(int z=0;z<4;z++){
    direction = turn(direction);
    if(direction==0 && a==1){
      surround++;
      continue;
    }
    if(direction==1 && b==(len-2)){
      surround++;
      continue;
    }
    if(direction==2 && a==(len-2)){
      surround++;
      continue;
    }
    if(direction==3 && b==1){
      surround++;
      continue;
    }
    try=connection(a,b,0,direction,maze);
    if(try==-1){
      return 0;
    }
    else{
      surround+=try;
    }
  }  //printf("\n");
  if(surround==4){        //미로 크기가 엄청 클때는 효과를 줄 수도 있겠지만 크키 200 이내에서는 거의 쓰이지 않는 것 같다.
    int done=1;
    while(done){
      switch (direction) {
        case 0:{
          if(a!=1){
            up.wall=0;
            done--;
          }
          else{
            direction++;
          }
        }break;
        case 1:{
          if(b!=(len-2)){
            right.wall=0;
            done--;
          }
          else{
            direction+=2;
          }
        }break;
        case 2:{
          if(a!=(len-2)){
            down.wall=0;
            done--;
          }
          else{
            direction-=2;
          }
        }break;
        case 3:{
          if(b!=1){
            left.wall=0;
            done--;
          }
          else{
            direction--;
          }
        }break;
      }
    }
  }
  return 1;
}

int void_chain(int a,int b,block**maze){
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
  return 0;
}

int turn(int direction){
  switch(direction){
    case 0:{    //up
      return direction+1;
    }break;
    case 1:{  //right
      return direction+2;
    }break;
    case 2:{  //down
      return direction-2;
    }break;
    case 3:{  //left
      return direction-1;
    }break;
  }
}

int connection(int a,int b, int level,int direction,block**maze){
  int next[2][4];
  if(direction==0){ //베열 음수 건들면 터짐 못건들게 if절로 막아둠
    next[0][0]=maze[a-2][b].path;
    next[1][0]=maze[a-2][b].root;
  }
  else if(direction==1){
    next[0][1]=maze[a][b+2].path;
    next[1][1]=maze[a][b+2].root;
  }
  else if(direction==2){
    next[0][2]=maze[a+2][b].path;
    next[1][2]=maze[a+2][b].root;
  }
  else if(direction==3){
    next[0][3]=maze[a][b-2].path;
    next[1][3]=maze[a][b-2].root;
  }
  if(next[level][direction]==1){
    switch (direction) {
      case 0:{
        up.wall=level;  //동기화는 일치화가 아니다. = 붙여주고 둘이 완전히 일치하다고 생각하면 안됨
      }break;           //어디까지나 값을 주고받는 것이지 상수 너무 썼다고 변수도 상수취급하듯이 취급해버리니깐 몇시간 날려먹음
      case 1:{
        right.wall=level;
      }break;
      case 2:{
        down.wall=level;
      }break;
      case 3:{
        left.wall=level;
      }
    }
    if(level){
      me.root=1;
      root_chain(a,b,maze);
    }
    else{
      me.path=1;
      void_chain(a,b,maze);
    }
    return -1;
  }
  int wall_dr[4];
  wall_dr[0]=up.wall;
  wall_dr[1]=right.wall;
  wall_dr[2]=down.wall;
  wall_dr[3]=left.wall;
  int surround=0;
  if(wall_dr[direction]==1){
    surround++;
  }
  return surround;
}

void path_clear(block**maze){ //new!!
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      me.path=0;
    }
  }
}

void solution(block**maze){
  door_push(maze);  //door close
  path_clear(maze);
  maze[1][1].path=1;
  path_search(1,1,maze);//path_check(maze);
  maze[len-2][len-2].cline=1;//len-2서부터 시작
  path_find(len-2,len-2,maze);
  door_push(maze);  //door open
  //cline_check(maze);
}

void path_search(int a,int b,block**maze){//new!!
  if(up.wall==0){
    if(maze[a-2][b].path==0){
      maze[a-2][b].path+=me.path+1;
      path_search(a-2,b,maze);
    }
  }
  if(right.wall==0){
    if(maze[a][b+2].path==0){
      maze[a][b+2].path+=me.path+1;
      path_search(a,b+2,maze);
    }
  }
  if(down.wall==0){
    if(maze[a+2][b].path==0){
      maze[a+2][b].path+=me.path+1;
      path_search(a+2,b,maze);
    }
  }
  if(left.wall==0){
    if(maze[a][b-2].path==0){
      maze[a][b-2].path+=me.path+1;
      path_search(a,b-2,maze);
    }
  }
}

void path_find(int a,int b,block**maze){
  if(up.wall==0){
    if(me.path-maze[a-2][b].path==1){//      printf("%d",me.path);
      maze[a-2][b].cline=1;//      printf("/%d/",maze[a-2][b].cline);
      path_find(a-2,b,maze);
    }
  }
  if(right.wall==0){
    if(me.path-maze[a][b+2].path == 1){//      printf("%d",me.path);
      maze[a][b+2].cline=1;//      printf("/%d/",maze[a][b+2].cline);
      path_find(a,b+2,maze);
    }
  }
  if(down.wall==0){
    if(me.path-maze[a+2][b].path== 1){//      printf("%d",me.path);
      maze[a+2][b].cline=1;//      printf("/%d/",maze[a+2][b].cline);
      path_find(a+2,b,maze);
    }
  }
  if(left.wall==0){
    if(me.path-maze[a][b-2].path== 1){//      printf("%d",me.path);
      maze[a][b-2].cline=1;//      printf("/%d/",maze[a][b-2].cline);
      path_find(a,b-2,maze);
    }
  }
}

void door_push(block**maze){
  if(maze[1][0].wall){
    maze[1][0].wall=0;
    maze[len-2][len-1].wall=0;
  }
  else{
    maze[1][0].wall=1;
    maze[len-2][len-1].wall=1;
  }
}

void path_check(block**maze){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.path){
        printf("%d",me.path);
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
void cline_check(block**maze){ //new!!
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.cline==1){
        printf("■");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}

void solution_check(block**maze){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.wall){
        printf("■");
      }
      else if(me.cline==1){
        printf("@ ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
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

void back_to_startline(){
  char check;
  printf("새로 구하고자 한다면 any키를 입력하시오");
  scanf(" %c",&check);
  system("cls");
}
