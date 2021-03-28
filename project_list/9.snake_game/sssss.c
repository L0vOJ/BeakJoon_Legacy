#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>

#define len 25  //���� ���� len-2�̴�

#define up map[a-1][b]
#define down map[a+1][b]
#define left map[a][b-1]
#define right map[a][b+1]
#define me map[a][b]
#define stand map[head->y][head->x] //head�� �� �ִ� map�󿡼��� ��ġ

typedef struct{
  int wall;
  int life;
}block;

typedef struct{
  int x;
  int y;
  int count;
  char direction;
}locate;

block** block_init();
void next_turn(block** map,locate* head);
int move(locate* head,block** map,char previous);
void wall_check(block**map);
void head_init(locate* head);
int control();

int main(){
  srand(time(0));
  block** map;
  locate* head;
  int fx,fy;
  char previous=2;
  map = block_init();
  head_init(head);
  fx = 1+rand()%(len-3);
  fy = 1+rand()%(len-3);
  map[fy][fx].wall=2;
  map[fy][fx].life=-1;
  while(1){
    wall_check(map);
    Sleep(200);
    previous = move(head,map,previous);
    if(stand.wall == 1){
      break;
    }
    else if(stand.wall == 2){
      head->count++;
      do{
        fx = 1+rand()%(len-3);
        fy = 1+rand()%(len-3);
      }while(map[fy][fx].wall == 1 || (fx == head->x && fy == head->y));
      map[fy][fx].wall=2;
      map[fy][fx].life=-1;
      stand.wall=1;
    }
    else{
      next_turn(map,head);
    }
    system("cls");
  }
  printf("\ngame over!");
}

block** block_init(){
  block** maze;   //**maze=���� *maze ������ maze ����������
  maze=(block**)calloc(len,sizeof(block));
  for(int a=0;a<len;a++){
    *(maze+a)=(block*)calloc(len,sizeof(block));
  }
  for(int a=0;a<len;a++){
    maze[0][a].wall=1;
    maze[a][0].wall=1;
    maze[len-1][a].wall=1;
    maze[a][len-1].wall=1;
    maze[0][a].life=-1;
    maze[a][0].life=-1;
    maze[len-1][a].life=-1;
    maze[a][len-1].life=-1;
  }
  return maze;
}

void head_init(locate* head){
  head->x=1;
  head->y=0;
  head->count=1;
  head->direction=2;
}

void next_turn(block** map,locate* head){
  for(int a=1;a<len-1;a++){
    for(int b=1;b<len-1;b++){
      if(me.life>0){
        me.life--;
        me.wall=1;
      }
      else if(me.life==0){
        me.wall=0;
      }
    }
  }
}

int move(locate* head,block** map,char previous){
  if(kbhit()){
    previous = head->direction;
    head->direction = control();  //getch();
  }
  if(previous + head->direction == 10){
    head->direction = previous;
  }
  switch(head->direction){
    case 8:{
      head->y--;
    }break;
    case 2:{
      head->y++;
    }break;
    case 4:{
      head->x--;
    }break;
    case 6:{
      head->x++;
    }break;
  }
  stand.life=head->count; //�ش� �ڸ��� life�� �ο�
  return previous;
}

int control(){
  switch(getch()){
    case 'w':{return 8;}break;
    case 's':{return 2;}break;
    case 'a':{return 4;}break;
    case 'd':{return 6;}break;
  }
}

void wall_check(block**map){
  for(int a=0;a<len;a++){
    for(int b=0;b<len;b++){
      if(me.wall==1){
        printf("��");
      }
      else if(me.wall==2){
        printf("@@");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
}
