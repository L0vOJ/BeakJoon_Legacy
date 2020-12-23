#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<windows.h>

#define len 25  //내부 폭은 len-2이다

#define mep map[a][b]
#define standout map[head->y][head->x] //head가 서 있는 map상에서의 위치
#define standin map[head.y][head.x]

typedef struct{
  int wall;
  int life;
}box;

typedef struct{
  int x;
  int y;
  int count;
  char direction;
}locate;

box** box_init();
void box_default(box** map);
void next_turn(box** map,locate* head);
void move(locate* head,box** map);
void snake_check(box**map);
void head_init(locate* head);
void food_init(box** map, int fx, int fy);

int main(){
  srand(time(0));
  char onoff =1;
  box** map = box_init();
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
      Sleep(200);
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
      system("cls");
    }
    printf("\ngame over!");
    char zz;
    while(1){
      printf("\nrestart? Y/N:");
      zz = getch();
      if(zz == 'y'){
        onoff = 1;
        break;
      }
      else if(zz == 'n'){
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
