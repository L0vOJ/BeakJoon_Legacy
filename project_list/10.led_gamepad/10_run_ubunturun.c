#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장545
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<time.h>

#define len 25
int effect=1;   //5번 이펙트 on=1, off=0

#define up maze[a-1][b]
#define down maze[a+1][b]
#define left maze[a][b-1]
#define right maze[a][b+1]
#define me maze[a][b]

#define ct_wall_len ((len-3)/2) //내부 고정벽 1열 개수
#define ct_void_len ((len-1)/2) //내부 고정공간 1열 개수

#define mep map[a][b]
#define standout map[head->y][head->x] //head가 서 있는 map상에서의 위치
#define standin map[head.y][head.x]

int level=1;
int route_sequence[1000];
int route_count=0;

typedef struct{
  int x;
  int y;
  int wall;
  int root;
  int path;
  int cline;
}block;

typedef struct{
  int wall;
  int life;
}box;

typedef struct{
  int x;
  int y;
  int num;
  int start;
  int seglen;
  int light[7];
}segment;

typedef struct{
  int x;
  int y;
  int count;
  char direction;
}locate;

box** box_init();
void convert(segment* flag);
void draw_map(segment* flag, box** map);
int menu_move(segment* flag);
void box_clear(box** map);
void snake_check(box**map);
//-------------아래는 뱀겜-------------
void snake_game(box** map);
void box_default(box** map);
void next_turn(box** map,locate* head);
void move(locate* head,box** map);
void head_init(locate* head);
void food_init(box** map, int fx, int fy);
//-------------아래는 미로---------------------------
void trevel_route(int a,int b,block**maze,int back);
void route_numbering(int a);
void draw_init(block** maze);
void draw_route(block**maze);
void route_order();
//미로 초기화 및 생성 함수
void block_clear(block**maze);
void solution_clear(block** maze);
void block_build(block**);
//in the block_build
//1단계:미로 기본구조 생성
block** block_init();
void rand_wall(block**maze);
//2단계:root
void root_link(block**maze);
void root_pruning(block**maze);
int root_plus(int a,int b,block**maze);
int root_chain(int a,int b,block**maze);
//3단계:void
void void_seed(block** maze);
void void_pruning(block**maze);
int void_plus(int a,int b,block**maze);
int void_chain(int a,int b,block**maze);
//-----------------------------------------
//미로 출구 찾는 함수
void solution(block**maze);
void path_clear(block**maze);
void path_search(int a,int b,block**maze);
void path_find(int a,int b,block**maze);
//미로의 멤버 확인 함수
void wall_check(block**maze);
void root_check(block**maze);
void void_check(block**maze);
void cline_check(block**maze);
void path_check(block**maze);
void solution_check(block**maze);
//잡기능은 아니지만 미분류함수
void door_push(block**maze);//미로 출입구 문 여닫기--일부 함수작용시 에러 막기 위함
int* queue();
void change(int* arr);
int connection(int a,int b, int level,int direction,block**maze);//**chain 작용의 핵심--root와 void 에서 최중요 작용
//main함수 인터페이스 함수
void operate(int want,block**maze);

int main(){
  srand(time(0));
  box** map = box_init();
  segment flag;
  flag.seglen=5;
  flag.x=5;
  flag.y=5;
  flag.num=2;
  flag.start=0;
  block**maze=block_init();
  block_build(maze);
  door_push(maze);
  while(1){
    convert(&flag);
    draw_map(&flag,map);
    snake_check(map);
    menu_move(&flag);
    if(flag.start){
      system("cls");
      if(flag.num==7){
        snake_game(map);
      }
      else{
        operate(flag.num,maze);
      }
      flag.start=0;
      getch();
    }
    box_clear(map);
    system("cls");
  }
}


void snake_game(box** map){
  char onoff =1;
  locate head;
  int fx,fy;
  while(1){
    box_default(map);
    head_init(&head);
    food_init(map,fx,fy);
    while(1){
      system("cls");
      snake_check(map);
      printf("\nlength:%d",head.count);
      Sleep(100);
      move(&head,map);
      if(standin.wall == 1){
        break;
      }
      else if(standin.wall == 2){
        head.count++;
        do{
          fx = 1+rand()%(len-3);
          fy = 1+rand()%(len-3);
        }while(map[fy][fx].wall == 1 || (fx == head.x && fy == head.y));
        map[fy][fx].wall=2;
        map[fy][fx].life=-1;
        standin.wall=1;
      }
      else{
        next_turn(map,&head);
      }
      Sleep(100);
    }
    printf("\ngame over!");
    char zz;
    while(1){
      printf("\nrestart? Y:z/N:c");
      zz = getch();
      if(zz == 'z'){
        onoff = 1;
        break;
      }
      else if(zz == 'c'){
        onoff = 0;
        break;
      }
      else{
        printf("wrong type\n");
      }
    }
    if(onoff == 0){
      break;
    }
  }
}

box** box_init(){
  box** maze;   //**maze=변수 *maze 포인터 maze 이중포인터
  maze=(box**)calloc(len,sizeof(box));
  for(int a=0;a<len;a++){
    *(maze+a)=(box*)calloc(len,sizeof(box));
  }
  for(int a=0;a<len;a++){
    maze[0][a].wall=1;
    maze[a][0].wall=1;
    maze[len-1][a].wall=1;
    maze[a][len-1].wall=1;
  }
  return maze;
}

void box_default(box** map){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      mep.life=0;
      mep.wall=0;
    }
  }
}

void head_init(locate* head){
  head->x=1;
  head->y=0;
  head->count=1;
  head->direction='s';
}

void food_init(box** map, int fx, int fy){
  fx = 1+rand()%(len-3);
  fy = 1+rand()%(len-3);
  map[fy][fx].wall=2;
  map[fy][fx].life=-1;
}

void next_turn(box** map,locate* head){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      if(mep.life>0){
        mep.life--;
        mep.wall=1;
      }
      else if(mep.life==0){
        mep.wall=0;
      }
    }
  }
}

void move(locate* head,box** map){
  char pre[2];
  char previous;
  if(kbhit()){
    previous = head->direction;
    pre[0] = head->direction;
    head->direction = getch();
    pre[1] = head->direction;
    for(int a=0;a<2;a++){
      switch(pre[a]){
        case 'w':{pre[a] = 8;}break;
        case 's':{pre[a] = 2;}break;
        case 'a':{pre[a] = 4;}break;
        case 'd':{pre[a] = 6;}break;
      }
    }
    if(pre[0] + pre[1] == 10){
      head->direction = previous;
    }
  }
  switch(head->direction){
    case 'w':{
      head->y--;
    }break;
    case 's':{
      head->y++;
    }break;
    case 'a':{
      head->x--;
    }break;
    case 'd':{
      head->x++;
    }break;
  }
  standout.life=head->count; //해당 자리에 life값 부여
}

void operate(int want,block**maze){
  switch(want){
    case 1:{
      wall_check(maze);
    }break;
    case 2:{
    if(level==1){
      solution(maze);
      level=2;
    }
    solution_check(maze);
    printf("출구까지의 거리는 %d\n",maze[len-2][len-2].path);
    }break;
    case 3:{
      block_clear(maze);
      door_push(maze);
      block_build(maze);
      door_push(maze);
      level=1;
      printf("초기화 완료!\n");
    }break;
    case 4:{
      draw_init(maze);
      draw_route(maze);
      //route_order();
    }break;
    case 5:{
      if(level==1){
        solution(maze);
        level=2;
      }
      if(level == 2){
        solution_clear(maze);
      }
      if(effect){
        draw_init(maze);
        draw_route(maze);
      }
      system("cls");
      char type;
      int a=1,b=0;
      me.cline=1;
      solution_check(maze);
      while(1){
        type = getch();
        switch(type){
          case 'w':{
            if(up.wall==0){
              if(up.cline == 0){//      printf("%d",me.path);
                up.cline=1;
              }
              else if(up.cline == 1){
                me.cline=0;
              }
              a--;
            }
          }break;
          case 's':{
            if(down.wall==0){
              if(down.cline == 0){//      printf("%d",me.path);
                down.cline=1;
              }
              else if(down.cline == 1){
                me.cline=0;
              }
              a++;
            }
          }break;
          case 'a':{
            if(a>0 && left.wall==0){
              if(left.cline == 0){//      printf("%d",me.path);
                left.cline=1;
              }
              else if(left.cline == 1){
                me.cline=0;
              }
              b--;
            }
          }break;
          case 'd':{
            if(a<len-1 && right.wall==0){
              if(right.cline == 0){//      printf("%d",me.path);
                right.cline=1;
              }
              else if(right.cline == 1){
                me.cline=0;
              }
              b++;
            }
          }break;
          case 'x':{
            if(b == 0){
              break;
            }
            me.cline=0;
            if(up.cline == 1){
              a--;
            }
            else if(down.cline == 1){
              a++;
            }
            else if(right.cline == 1){
              b++;
            }
            else if(left.cline == 1){
              b--;
            }
          }break;
        }
        system("cls");
        solution_check(maze);
        if(a == len-2 && b == len-1){
          printf("\nsolved!");
          break;
        }
      }
    }break;
    case 6:{
      if(effect == 0){
        printf("생성 이펙트 on\n");
        effect = 1;
      }
      else{
        printf("생성 이펙트 off\n");
        effect = 0;
      }
    }
  }
}

void box_clear(box** map){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      mep.wall=0;
    }
  }
}

void convert(segment* flag){
  for(int a=0;a<7;a++){
    flag->light[a]=1;
  }
  if(flag->num==1 || flag->num==4){
    flag->light[0]=0;
  }
  if(flag->num==0 || flag->num==1 ||flag->num==7){
    flag->light[1]=0;
  }
  if(flag->num==1||flag->num==4||flag->num==7){
    flag->light[2]=0;
  }
  if(flag->num==1||flag->num==2||flag->num==3||flag->num==7){
    flag->light[3]=0;
  }
  if(flag->num==5||flag->num==6){
    flag->light[4]=0;
  }
  if(flag->num==1||flag->num==3||flag->num==4||flag->num==5||flag->num==7||flag->num==9){
    flag->light[5]=0;
  }
  if(flag->num==2){
    flag->light[6]=0;
  }
}

void draw_map(segment* flag, box** map){
  for(int i=0;i<3;i++){
    for(int b=0;b<flag->seglen;b++){
      if(flag->light[i]){
        map[flag->y+(i*(flag->seglen+1))][flag->x+b+1].wall=1;
      }
    }
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      for(int b=0;b<flag->seglen;b++){
        if(flag->light[3+j+(2*i)]){
          map[flag->y+b+1+(i*(flag->seglen+1))][flag->x+(j*(flag->seglen+1))].wall=1;
        }
      }
    }
  }
}

int menu_move(segment* flag){
  char type=getch();
  switch(type){
    case 'w':{
      if(flag->y>1){
        flag->y--;
      }
    }break;
    case 's':{
      if(flag->y<len-(2 * flag->seglen)-4){
        flag->y++;
      }
    }break;
    case 'a':{
      if(flag->x>1){
        flag->x--;
      }
    }break;
    case 'd':{
      if(flag->x<len-flag->seglen-3){
        flag->x++;
      }
    }break;
    case 'z':{
      if(flag->seglen>2){
        flag->seglen--;
      }
    }break;
    case 'c':{
      if(flag->seglen<10){
        if(flag->x==len-flag->seglen-3){
          flag->x--;
        }
        if(flag->y>=len-(2 * flag->seglen)-5){
          flag->y=len-(2*flag->seglen)-6;
        }
        flag->seglen++;
      }
    }break;
    case 'q':{
      if(flag->num==1){
        flag->num=7;
      }
      else{
        flag->num--;
      }
    }break;
    case 'e':{
      if(flag->num>6){
        flag->num=1;
      }
      else{
        flag->num++;
      }
    }break;
    case 'x':{
      flag->start=1;
    }break;
    default:{
      flag->num=type-48;
    }break;
  }
}


void draw_init(block** maze){
  for(int a=0;a<route_count;a++){ //----------------
    route_sequence[a]=0;
  }
  route_count=0;    //---------루트시퀸스 초기화
  for(int a=1;a<len-1;a++){       //--루트값 초기화
    for(int b=1;b<len-1;b++){
      me.root=0;
    }
  }
}
void draw_route(block**maze){
  for(int a=2;a<len-1;a+=2){
    route_numbering(2);
    if(maze[1][a].wall==1){
      maze[1][a].root=1;
      system("cls");
      root_check(maze);
      maze[2][a].root=1;
      system("cls");
      root_check(maze);
      route_numbering(3); //down 명령
      trevel_route(2,a,maze,1); //up 회수
    }
  }
  route_numbering(2);
  for(int a=2;a<len-1;a+=2){
    route_numbering(3);
    if(maze[a][len-2].wall==1){
      maze[a][len-2].root=1;
      system("cls");
      root_check(maze);
      maze[a][len-3].root=1;
      system("cls");
      root_check(maze);
      route_numbering(4);
      trevel_route(a,len-3,maze,2);
    }
  }
  route_numbering(5);
  route_numbering(3);
  route_numbering(6);
  for(int a=len-3;a>1;a-=2){
    route_numbering(4);
    if(maze[len-2][a].wall==1){
      maze[len-2][a].root=1;
      system("cls");
      root_check(maze);
      maze[len-3][a].root=1;
      system("cls");
      root_check(maze);
      route_numbering(1);
      trevel_route(len-3,a,maze,3);
    }
  }
  route_numbering(4);
  for(int a=len-3;a>1;a-=2){
    route_numbering(1);
    if(maze[a][1].wall==1){
      maze[a][1].root=1;
      system("cls");
      root_check(maze);
      maze[a][2].root=1;
      system("cls");
      root_check(maze);
      route_numbering(2);
      trevel_route(a,2,maze,4);
    }
  }
}

void route_numbering(int a){
  route_sequence[route_count]=a;
  route_count++;
}

void trevel_route(int a,int b,block**maze,int back){
  if(up.wall==1){
    if(maze[a-2][b].root==0){
      up.root=1;
      system("cls");
      root_check(maze);
      maze[a-2][b].root=1;
      system("cls");
      root_check(maze);
      route_numbering(1); //up명령
      trevel_route(a-2,b,maze,3); //down회수
    }
  }
  if(right.wall==1){
    if(maze[a][b+2].root==0){
      right.root=1;
      system("cls");
      root_check(maze);
      maze[a][b+2].root=1;
      system("cls");
      root_check(maze);
      route_numbering(2);
      trevel_route(a,b+2,maze,4);
    }
  }
  if(down.wall==1){
    if(maze[a+2][b].root==0){
      down.root=1;
      system("cls");
      root_check(maze);
      maze[a+2][b].root=1;
      system("cls");
      root_check(maze);
      route_numbering(3);
      trevel_route(a+2,b,maze,1);
    }
  }
  if(left.wall==1){
    if(maze[a][b-2].root==0){
      left.root=1;
      system("cls");
      root_check(maze);
      maze[a][b-2].root=1;
      system("cls");
      root_check(maze);
      route_numbering(4);
      trevel_route(a,b-2,maze,2);
    }
  }
  route_numbering(back);
}

void route_order(){
  int a=0;
  while(route_sequence[a]){
    switch(route_sequence[a]){
      case 1:{
        printf("up()/");
      }break;
      case 2:{
        printf("right()/");
      }break;
      case 3:{
        printf("down()/");
      }break;
      case 4:{
        printf("left()/");
      }break;
      case 5:{
        printf("펜 떼기/");
      }break;
      case 6:{
        printf("펜 찍기/");
      }
    }
    if(a%8==7){
      printf("\n\n");
    }
    a++;
  }
  printf("%d",a);
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
  maze[1][0].cline=0;
  maze[len-2][len-1].cline=0;
  for(int a=2;a<len-2;a+=2){
    for(int b=2;b<len-2;b+=2){
      me.wall=1;
    }
  }
}

void solution_clear(block** maze){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      me.cline=0;
    }
  }
  maze[len-2][len-1].cline=0;
  maze[1][0].cline=1;
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
  maze=(block**)calloc(len,sizeof(block));
  for(int a=0;a<len;a++){
    *(maze+a)=(block*)calloc(len,sizeof(block));
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
  int try,surround=0;
  int* direction;
  direction=queue();
  for(int z=0;z<4;z++){
    try=connection(a,b,1,direction[z],maze);
    if(try==-1){
      free(direction);
      return 0;
    }
    else{
      surround=try;
    }
  }
  if(surround==0){
    switch (direction[3]) {
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
  free(direction);
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
  int try,surround=0;
  int* direction;
  direction=queue();
  for(int z=0;z<4;z++){
    if(direction[z]==0 && a==1){             //해당 방향으로 나아갈 수 없음-->그래서 둘러싸인 외벽의 개수 여부를 조사
      surround++;                         //+배열 음수값 인덱스 접근 방지
      continue;
    }
    if(direction[z]==1 && b==(len-2)){
      surround++;
      continue;
    }
    if(direction[z]==2 && a==(len-2)){
      surround++;
      continue;
    }
    if(direction[z]==3 && b==1){
      surround++;
      continue;
    }
    try=connection(a,b,0,direction[z],maze);   //해당 방향이 외부에 걸리지 않아 접근이 가능하다면 connection 호출
    if(try==-1){                            //연결 작업 성공적->함수 종결
      free(direction);
      return 0;
    }
    else{                                   //아니라면
      surround=try;                         //둘러싸인 벽 값 갱신 후 다음 direction에 대해 다시 수행
    }
  }  //printf("\n");
  if(surround==4){        //미로 크기가 엄청 클때는 효과를 줄 수도 있겠지만 크키 200 이내에서는 거의 쓰이지 않는 것 같다.
    int done=1;
    while(done){
      switch (direction[3]) {
        case 0:{
          if(a!=1){
            up.wall=0;
            done--;
          }
          else{
            direction[3]++;
          }
        }break;
        case 1:{
          if(b!=(len-2)){
            right.wall=0;
            done--;
          }
          else{
            direction[3]+=2;
          }
        }break;
        case 2:{
          if(a!=(len-2)){
            down.wall=0;
            done--;
          }
          else{
            direction[3]-=2;
          }
        }break;
        case 3:{
          if(b!=1){
            left.wall=0;
            done--;
          }
          else{
            direction[3]--;
          }
        }break;
      }
    }
  }
  free(direction);
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

int* queue(){
  int* arr;
  arr=calloc(4,sizeof(int));
  for(int a=0;a<4;a++){
    arr[a]=a;
  }
  for(int a=0;a<12;a++){
    change(arr);
  }
  return arr;
}

void change(int* arr){
  int buffer;
  int choice[2];
  for(int a=0;a<2;a++){
    choice[a]=rand()%4;    //rand 최대값: size-1; 배열 가장 큰 인덱스넘버와 같다
  }
  buffer = arr[choice[0]];
  arr[choice[0]] = arr[choice[1]];
  arr[choice[1]] = buffer; //교환 완료
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
  if(next[level][direction]==1){  //해당 방향으로 나아가야 한다면 level==0 --> 해당 방향으로 본 통로가 뚫려 있다면 leve==1 --> 해당 방향으로 외각과 이어진 뿌리가 있다면
    switch (direction) {          // level==0 벽을 허물거나  level==1 벽을 잇거나
      case 0:{
        up.wall=level;
      }break;
      case 1:{
        right.wall=level;
      }break;
      case 2:{
        down.wall=level;
      }break;
      case 3:{
        left.wall=level;
      }break;
    }
    if(level){                   //연쇄 작업 수행
      me.root=1;
      root_chain(a,b,maze);
    }
    else{
      me.path=1;
      void_chain(a,b,maze);
    }
    return -1;                  //연쇄 작업 완료
  }
  int wall_dr[4];               //연쇄 작업 수행 케이스가 아니라면 (주변 중요 연결 고리에 직접 연결되지 못했다면)
  wall_dr[0]=up.wall;
  wall_dr[1]=right.wall;
  wall_dr[2]=down.wall;
  wall_dr[3]=left.wall;
  int surround=0;
  if(wall_dr[direction]==1){
    surround++;
  }
  return surround;          //해당 방향으로 둘러싸인 내벽의 개수를 반환 --> 이를 통해 윗단계의 함수가 랜덤 연결 작업을 수행할지 결정함
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
  maze[1][0].cline=1;
  maze[len-2][len-1].cline=1;
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
      up.cline=1;
      maze[a-2][b].cline=1;//      printf("/%d/",maze[a-2][b].cline);
      path_find(a-2,b,maze);
    }
  }
  if(right.wall==0){
    if(me.path-maze[a][b+2].path == 1){//      printf("%d",me.path);
      right.cline=1;
      maze[a][b+2].cline=1;//      printf("/%d/",maze[a][b+2].cline);
      path_find(a,b+2,maze);
    }
  }
  if(down.wall==0){
    if(me.path-maze[a+2][b].path== 1){//      printf("%d",me.path);
      down.cline=1;
      maze[a+2][b].cline=1;//      printf("/%d/",maze[a+2][b].cline);
      path_find(a+2,b,maze);
    }
  }
  if(left.wall==0){
    if(me.path-maze[a][b-2].path== 1){//      printf("%d",me.path);
      left.cline=1;
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
      else if(me.cline){
        printf("**");
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

void snake_check(box**map){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(mep.wall==1){
        printf("■");
      }
      else if(mep.wall==2){
        printf("@@");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
