#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

#define len 25

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
  int num;
  int seglen;
  int light[7];
}segment;

box** box_init();
void convert(segment* flag);
void draw_map(segment* flag, box** map);
int menu_move(segment* flag);
void box_clear(box** map);
void snake_check(box**map);

int main(){
  box** map = box_init();
  segment flag;
  flag.seglen=5;
  flag.x=5;
  flag.y=5;
  flag.num=2;
  while(1){
    convert(&flag);
    draw_map(&flag,map);
    snake_check(map);
    menu_move(&flag);
    box_clear(map);
    system("cls");
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
    default:{
      flag->num=type-48;
    }break;
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
