#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<math.h>
#include<stddef.h>  //sizeof ������ ����

#define len 9  //������ Ȧ�����߸� �Ѵ�  4�ǹ�� +1�� ���� �����ϴ�

#define up maze[a-1][b]
#define down maze[a+1][b]
#define left maze[a][b-1]
#define right maze[a][b+1]
#define me maze[a][b]

#define ct_wall_len ((len-3)/2) //���� ������ 1�� ����
#define ct_void_len ((len-1)/2) //���� �������� 1�� ����

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
void draw_route(block**maze);
int route_order(char*);
//�̷� �ʱ�ȭ �� ���� �Լ�
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

void wall_check(block**maze);
//������ �ƴ����� �̺з��Լ�
void door_push(block**maze);//�̷� ���Ա� �� ���ݱ�--�Ϻ� �Լ��ۿ�� ���� ���� ����
int turn(int dddd);  //�̷� ������ chain Ž�� ���� ���� �Լ�
int connection(int a,int b, int level,int dddd,block**maze);//**chain �ۿ��� �ٽ�--root�� void ���� ���߿� �ۿ�

int main(){
  block** maze=block_init();
  block_build(maze);
  for(int a=1;a<len-1;a++){       //--��Ʈ�� �ʱ�ȭ
    for(int b=1;b<len-1;b++){
      me.root=0;
    }
  }
  draw_route(maze);
  char direc_order[1000];
  int a = route_order(direc_order);
  int t=0;
  for(t;t<a;t++){
    printf("%d",direc_order[t]);
  }
  wall_check(maze);
}

void draw_route(block**maze){
  for(int a=2;a<len-1;a+=2){
    route_numbering(2);
    if(maze[1][a].wall==1){
      maze[1][a].root=1;
      maze[2][a].root=1;
      route_numbering(3); //down ���
      trevel_route(2,a,maze,1); //up ȸ��
    }
  }
  route_numbering(2);
  for(int a=2;a<len-1;a+=2){
    route_numbering(3);
    if(maze[a][len-2].wall==1){
      maze[a][len-2].root=1;
      maze[a][len-3].root=1;
      route_numbering(4);
      trevel_route(a,len-3,maze,2);
    }
  }
  //route_numbering(5);
  route_numbering(3);
  //route_numbering(6);
  for(int a=len-3;a>1;a-=2){
    route_numbering(4);
    if(maze[len-2][a].wall==1){
      maze[len-2][a].root=1;
      maze[len-3][a].root=1;
      route_numbering(1);
      trevel_route(len-3,a,maze,3);
    }
  }
  route_numbering(4);
  for(int a=len-3;a>1;a-=2){
    route_numbering(1);
    if(maze[a][1].wall==1){
      maze[a][1].root=1;
      maze[a][2].root=1;
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
      maze[a-2][b].root=1;
      route_numbering(1); //up���
      trevel_route(a-2,b,maze,3); //downȸ��
    }
  }
  if(right.wall==1){
    if(maze[a][b+2].root==0){
      right.root=1;
      maze[a][b+2].root=1;
      route_numbering(2);
      trevel_route(a,b+2,maze,4);
    }
  }
  if(down.wall==1){
    if(maze[a+2][b].root==0){
      down.root=1;
      maze[a+2][b].root=1;
      route_numbering(3);
      trevel_route(a+2,b,maze,1);
    }
  }
  if(left.wall==1){
    if(maze[a][b-2].root==0){
      left.root=1;
      maze[a][b-2].root=1;
      route_numbering(4);
      trevel_route(a,b-2,maze,2);
    }
  }
  route_numbering(back);
}

int route_order(char* direc_order){
  int a=0;
  while(route_sequence[a]){
    if(a%8==7){
      //printf("\n\n");
    }
    if(route_sequence[a]>0 && route_sequence[a]<5){
      if(a==0){
        //printf("go(%d)/",route_sequence[a]);
        direc_order[a]=1;
        a++;
        continue;
      }
      if(route_sequence[a-1]>0 && route_sequence[a-1]<5){
        int dif = route_sequence[a]-route_sequence[a-1];
        if(dif==0){
          //printf("go(%d)/",route_sequence[a]);
          direc_order[a]=1;
          a++;
          continue;
        }
        if(dif == 2 || dif == -2){
          //printf("backturn(%d)/",route_sequence[a]);
          direc_order[a]=3;
          a++;
          continue;
        }
        if(dif==1 || dif==-3){
          //printf("right(%d)/",route_sequence[a]);
          direc_order[a]=2;
          a++;
          continue;
        }
        if(dif==-1 || dif==3){
        //  printf("left(%d)/",route_sequence[a]);
          direc_order[a]=4;
          a++;
          continue;
        }
      }
      /*
      if(route_sequence[a-1]==5){
      //  printf("go(%d)/",route_sequence[a]);
        direc_order[a]=1;
        a++;
        continue;
      }
      if(route_sequence[a-1]==6){
      //  printf("right(%d)/",route_sequence[a]);
        direc_order[a]=2;
        a++;
        continue;
      }
      */
    }
    if(route_sequence[a]==5){
  //    printf("�� ����(%d)/",route_sequence[a]);
      direc_order[a]=5;
      a++;
      continue;
    }
    if(route_sequence[a]==6){
//      printf("�� ���(%d)/",route_sequence[a]);
      direc_order[a]=6;
      a++;
      continue;
    }
//    printf("���� ������ �ȵ� ���� �̰� ������ �ȵ�");
  }
//  printf("%d",a);
//  printf("\n");
  return a;
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

  int a,b,tap=0;
  while(1){
    a=1+random(len-2);             //a:1~15
    if(a%2){                          //a�� Ȧ�����
      b=2*(1+random(ct_wall_len));     //b:2,4,6...14 //�� 7��
    }
    else{
      b=1+2*random(ct_void_len);          //b:1,3,5...15 //�� 8��
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

  int dddd,gogo,surround=0;
  dddd=random(4);                    //printf("%d",dddd);
  for(int z=0;z<4;z++){
    gogo=connection(a,b,1,dddd,maze);
    if(gogo==-1){
      return 0;
    }
    else{
      surround+=gogo;
    }
    dddd = turn(dddd);
  }
  if(surround==0){
    switch (dddd) {
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

  int dddd,gogo,surround=0;
  dddd=random(4);                    //printf("%d",dddd);
  for(int z=0;z<4;z++){
    dddd = turn(dddd);
    if(dddd==0 && a==1){
      surround++;
      continue;
    }
    if(dddd==1 && b==(len-2)){
      surround++;
      continue;
    }
    if(dddd==2 && a==(len-2)){
      surround++;
      continue;
    }
    if(dddd==3 && b==1){
      surround++;
      continue;
    }
    gogo=connection(a,b,0,dddd,maze);
    if(gogo==-1){
      return 0;
    }
    else{
      surround+=gogo;
    }
  }  //printf("\n");
  if(surround==4){        //�̷� ũ�Ⱑ ��û Ŭ���� ȿ���� �� ���� �ְ����� ũŰ 200 �̳������� ���� ������ �ʴ� �� ����.
    int done=1;
    while(done){
      switch (dddd) {
        case 0:{
          if(a!=1){
            up.wall=0;
            done--;
          }
          else{
            dddd++;
          }
        }break;
        case 1:{
          if(b!=(len-2)){
            right.wall=0;
            done--;
          }
          else{
            dddd+=2;
          }
        }break;
        case 2:{
          if(a!=(len-2)){
            down.wall=0;
            done--;
          }
          else{
            dddd-=2;
          }
        }break;
        case 3:{
          if(b!=1){
            left.wall=0;
            done--;
          }
          else{
            dddd--;
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

int turn(int dddd){
  switch(dddd){
    case 0:{    //up
      return dddd+1;
    }break;
    case 1:{  //right
      return dddd+2;
    }break;
    case 2:{  //down
      return dddd-2;
    }break;
    case 3:{  //left
      return dddd-1;
    }break;
  }
}

int connection(int a,int b, int level,int dddd,block**maze){
  int next[2][4];
  if(dddd==0){ //���� ���� �ǵ�� ���� ���ǵ�� if���� ���Ƶ�
    next[0][0]=maze[a-2][b].path;
    next[1][0]=maze[a-2][b].root;
  }
  else if(dddd==1){
    next[0][1]=maze[a][b+2].path;
    next[1][1]=maze[a][b+2].root;
  }
  else if(dddd==2){
    next[0][2]=maze[a+2][b].path;
    next[1][2]=maze[a+2][b].root;
  }
  else if(dddd==3){
    next[0][3]=maze[a][b-2].path;
    next[1][3]=maze[a][b-2].root;
  }
  if(next[level][dddd]==1){
    switch (dddd) {
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
      }break;
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
  if(wall_dr[dddd]==1){
    surround++;
  }
  return surround;
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
