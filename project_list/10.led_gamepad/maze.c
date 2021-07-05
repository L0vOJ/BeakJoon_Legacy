#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>

#define len 25  //������ Ȧ�����߸� �Ѵ�  4�ǹ�� +1�� ���� �����ϴ�  //57�� ��üȭ������ ���� ���� ���� //������δ� 37�� ���� ���� ����
int effect=1;   //5�� ����Ʈ on=1, off=0

#define up maze[a-1][b]
#define down maze[a+1][b]
#define left maze[a][b-1]
#define right maze[a][b+1]
#define me maze[a][b]

#define ct_wall_len ((len-3)/2) //���� ������ 1�� ����
#define ct_void_len ((len-1)/2) //���� �������� 1�� ����

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
//adventure design�� �̷α׸��� �� ��� ���� �Լ�
void trevel_route(int a,int b,block**maze,int back);
void route_numbering(int a);
void draw_init(block** maze);
void draw_route(block**maze);
void route_order();
//�̷� �ʱ�ȭ �� ���� �Լ�
void block_clear(block**maze);
void solution_clear(block** maze);
void block_build(block**);
//in the block_build
//1�ܰ�:�̷� �⺻���� ����
block** block_init();
void rand_wall(block**maze);
//2�ܰ�:root
void root_link(block**maze);
void root_pruning(block**maze);
int root_plus(int a,int b,block**maze);
int root_chain(int a,int b,block**maze);
//3�ܰ�:void
void void_seed(block** maze);
void void_pruning(block**maze);
int void_plus(int a,int b,block**maze);
int void_chain(int a,int b,block**maze);
//-----------------------------------------
//�̷� �ⱸ ã�� �Լ�
void solution(block**maze);
void path_clear(block**maze);
void path_search(int a,int b,block**maze);
void path_find(int a,int b,block**maze);
//�̷��� ��� Ȯ�� �Լ�
void wall_check(block**maze);
void root_check(block**maze);
void void_check(block**maze);
void cline_check(block**maze);
void path_check(block**maze);
void solution_check(block**maze);
//������ �ƴ����� �̺з��Լ�
void door_push(block**maze);//�̷� ���Ա� �� ���ݱ�--�Ϻ� �Լ��ۿ�� ���� ���� ����
int* queue();
void change(int* arr);
int connection(int a,int b, int level,int direction,block**maze);//**chain �ۿ��� �ٽ�--root�� void ���� ���߿� �ۿ�
//main�Լ� �������̽� �Լ�
void operate(int want,block**maze);
void back_to_startline();
//--------------------------------------------

int main(){
  int want;
  block**maze=block_init();
  block_build(maze);
  door_push(maze);
  while(1){
    printf("~~maze generator and path finder~~\n");
    printf("�̷� ������ ����ϰ�ʹٸ� 1����, �̷��� �ش��� ã��ʹٸ� 2����, �̷θ� �ʱ�ȭ�Ϸ��� 3���� �Է��ϼ���\n");
    printf("�̵� ��� ������� �� �����ϴ� ���� ����ʹٸ� 4���� �Է��ϼ���\n");
    printf("�̷θ� ���� Ǯ�������� 5���� �Է��ϼ���\n");
    printf("5�� ���ý� ����ȿ���� Ű�ų� ���� ������ 6���� �Է��ϼ���\n");
    scanf("%d",&want);
    operate(want,maze);
    back_to_startline();
  }
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
    printf("�ⱸ������ �Ÿ��� %d\n",maze[len-2][len-2].path);
    }break;
    case 3:{
      block_clear(maze);
      door_push(maze);
      block_build(maze);
      door_push(maze);
      level=1;
      printf("�ʱ�ȭ �Ϸ�!\n");
    }break;
    case 4:{
      draw_init(maze);
      draw_route(maze);
      route_order();
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
          case 'r':{
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
        printf("���� ����Ʈ on\n");
        effect = 1;
      }
      else{
        printf("���� ����Ʈ off\n");
        effect = 0;
      }
    }
  }
}

void draw_init(block** maze){
  for(int a=0;a<route_count;a++){ //----------------
    route_sequence[a]=0;
  }
  route_count=0;    //---------��Ʈ������ �ʱ�ȭ
  for(int a=1;a<len-1;a++){       //--��Ʈ�� �ʱ�ȭ
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
      route_numbering(3); //down ���
      trevel_route(2,a,maze,1); //up ȸ��
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
      route_numbering(1); //up���
      trevel_route(a-2,b,maze,3); //downȸ��
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
        printf("�� ����/");
      }break;
      case 6:{
        printf("�� ���/");
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
  int try,surround=0;
  int* direction;
  direction=queue();
  for(int z=0;z<4;z++){
    if(direction[z]==0 && a==1){             //�ش� �������� ���ư� �� ����-->�׷��� �ѷ����� �ܺ��� ���� ���θ� ����
      surround++;                         //+�迭 ������ �ε��� ���� ����
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
    try=connection(a,b,0,direction[z],maze);   //�ش� ������ �ܺο� �ɸ��� �ʾ� ������ �����ϴٸ� connection ȣ��
    if(try==-1){                            //���� �۾� ������->�Լ� ����
      free(direction);
      return 0;
    }
    else{                                   //�ƴ϶��
      surround=try;                         //�ѷ����� �� �� ���� �� ���� direction�� ���� �ٽ� ����
    }
  }  //printf("\n");
  if(surround==4){        //�̷� ũ�Ⱑ ��û Ŭ���� ȿ���� �� ���� �ְ����� ũŰ 200 �̳������� ���� ������ �ʴ� �� ����.
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
    choice[a]=rand()%4;    //rand �ִ밪: size-1; �迭 ���� ū �ε����ѹ��� ����
  }
  buffer = arr[choice[0]];
  arr[choice[0]] = arr[choice[1]];
  arr[choice[1]] = buffer; //��ȯ �Ϸ�
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
  if(next[level][direction]==1){  //�ش� �������� ���ư��� �Ѵٸ� level==0 --> �ش� �������� �� ��ΰ� �շ� �ִٸ� leve==1 --> �ش� �������� �ܰ��� �̾��� �Ѹ��� �ִٸ�
    switch (direction) {          // level==0 ���� �㹰�ų�  level==1 ���� �հų�
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
    if(level){                   //���� �۾� ����
      me.root=1;
      root_chain(a,b,maze);
    }
    else{
      me.path=1;
      void_chain(a,b,maze);
    }
    return -1;                  //���� �۾� �Ϸ�
  }
  int wall_dr[4];               //���� �۾� ���� ���̽��� �ƴ϶�� (�ֺ� �߿� ���� ���� ���� ������� ���ߴٸ�)
  wall_dr[0]=up.wall;
  wall_dr[1]=right.wall;
  wall_dr[2]=down.wall;
  wall_dr[3]=left.wall;
  int surround=0;
  if(wall_dr[direction]==1){
    surround++;
  }
  return surround;          //�ش� �������� �ѷ����� ������ ������ ��ȯ --> �̸� ���� ���ܰ��� �Լ��� ���� ���� �۾��� �������� ������
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
