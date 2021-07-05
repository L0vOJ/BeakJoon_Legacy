#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>

#define len 53  //������ Ȧ�����߸� �Ѵ�  4�ǹ�� +1�� ���� �����ϴ�

#define up maze[a-1][b]
#define down maze[a+1][b]
#define left maze[a][b-1]
#define right maze[a][b+1]
#define me maze[a][b]

#define ct_wall_len ((len-3)/2) //���� ������ 1�� ����
#define ct_void_len ((len-1)/2) //���� �������� 1�� ����

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
    printf("�̷� ������ ����ϰ�ʹٸ� 1����, �̷��� �ش��� ã��ʹٸ� 2����, �̷θ� �ʱ�ȭ�Ϸ��� 3���� �Է��ϼ���\n");
    printf("���ӽ�:�̷��� ���̵��� �����ϰ� �ʹٸ� 4���� �Է����ֽʽÿ�");
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
    printf("�ⱸ������ �Ÿ��� %d\n",maze[len-2][len-2].path);
    }break;
    case 3:{
      block_clear(maze);
      block_build(maze);
      level=1;
      //printf("�ʱ�ȭ �Ϸ�!\n");
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

  root_link(maze);      //�ܺκ����κ��� ����
  root_pruning(maze);//  wall_check(maze);
  printf(" ");            //����! �ǵ��� ���� �� ���α׷��� ��ȥ�� ���

  void_seed(maze);      //�� ������ �߽ɿ������� ����
  void_pruning(maze);//  wall_check(maze);
  printf(" \r");          //���� root�۾��� void �۾��� ���ô��Ѵ� �������� �𸣰�����
      //�ߴ�:a�κп� (len-3)/2 ���:1 �ϴ�:len-2
}
//-------------------------------
block** block_init(){
  block** maze;   //**maze=���� *maze ������ maze ����������
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
    if(a%2){                          //a�� Ȧ�����
      b=2*(1+rand()%(ct_wall_len));     //b:2,4,6...14 //�� 7��
    }
    else{
      b=1+2*(rand()%(ct_void_len));          //b:1,3,5...15 //�� 8��
    }
    if(me.wall==0){         //�ű� ��ġ�϶�
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
    for(int a=2;a<len-2;a+=2){                //��, ���� �����ϰ� �̾Ҵµ�, �밢������ �˻��غ����� ����
      for(int b=2;b<len-2;b+=2){
        north = 2 + (a+b-4)%(len-3);          //len-3 =14 -- %�ִ�=13
        if(maze[north][b].root==0){
          not_yet += root_plus(north,b,maze);
        }
      }
    }       //�ּ�ó���� ����
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
    for(int a=3;a<len+1;a+=2){                //��, ���� �����ϰ� �̾Ҵµ�, �밢������ �˻��غ����� ����
      for(int b=len-2;b>0;b-=2){
        north = 1 + (a+b-2)%(len-1);          //len-3 =14 -- %�ִ�=13
        if(maze[north][b].path==0){
          not_yet += void_plus(north,b,maze);
        }
      }                       //�̹��� [3][3]�� �� �ڴ�� path���� ���� ��� ó����
    }       //�ּ�ó���� ����  //���迬���� ==��� �ľߵǴµ� =��� �ļ� case=1 ���� �Ը��� �޲�
  }  //printf("������?\n");   //maze[-1] �̷��� �ǵ鿩�� �����°��� ���� ��� ������ //ó���ص�Ƚ��ϴ�^^
}


int void_plus(int a,int b,block**maze){   //me.path==1, �������� ���ְ� �׳� �ֺ� ��� �� ������
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
  if(surround==4){        //�̷� ũ�Ⱑ ��û Ŭ���� ȿ���� �� ���� �ְ����� ũŰ 200 �̳������� ���� ������ �ʴ� �� ����.
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
  if(direction==0){ //���� ���� �ǵ�� ���� ���ǵ�� if���� ���Ƶ�
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
        up.wall=level;  //����ȭ�� ��ġȭ�� �ƴϴ�. = �ٿ��ְ� ���� ������ ��ġ�ϴٰ� �����ϸ� �ȵ�
      }break;           //�������� ���� �ְ�޴� ������ ��� �ʹ� ��ٰ� ������ �������ϵ��� ����ع����ϱ� ��ð� ��������
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
  maze[len-2][len-2].cline=1;//len-2������ ����
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
        printf("��");
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
        printf("��");
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
        printf("��");
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
        printf("��");
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
        printf("��");
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
  printf("���� ���ϰ��� �Ѵٸ� anyŰ�� �Է��Ͻÿ�");
  scanf(" %c",&check);
  system("cls");
}
