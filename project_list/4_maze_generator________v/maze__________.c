#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
#include<windows.h>
#define len 105  //������ Ȧ�����߸� �Ѵ�  4�ǹ�� +1�� ���� �����ϴ�

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

  root_link(maze);      //�ܺκ����κ��� ����
  root_pruning(maze);//  wall_check(maze);
  printf("1");            //����! �ǵ��� ���� �� ���α׷��� ��ȥ�� ���

  void_seed(maze);      //�� ������ �߽ɿ������� ����
  void_pruning(maze);//  wall_check(maze);
  printf("2\n");          //���� root�۾��� void �۾��� ���ô��Ѵ� �������� �𸣰�����
  maze[1][0].wall=0;
  maze[len-2][len-1].wall=0;        //�ߴ�:a�κп� (len-3)/2 ���:1 �ϴ�:len-2
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
