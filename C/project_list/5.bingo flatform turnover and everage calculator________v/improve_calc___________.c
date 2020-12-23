#include<stdio.h>
#include<stdlib.h>  //동적 할당 내장
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof 연산자 내장
#include<windows.h>

typedef struct{
  double table;
  int goal;
  int count;
  int setting;
} there;

typedef struct{
  double calc_save; //= malloc(goal*sizeof(*calc_save));  // calc_save[8];
  int depth;
  int progress;
} here;
//----------------함수
void update_val(there*);
void update_setting(there*);

double allc_calc(there);  //여기서 allc는 all Clear(중복 없이 한번에 목표까지 도달할 확률)이다.
here* var_init(there);
double var_calc(int ,here*,there);

double sum_prob(double,there);
double avr(double,there);
double dispersion(double,there);

void menu(double,there);
void display(double,there);
double tap_prob(double,there,int);
void back_to_startline();
//-------------------------------------------
int main(){
  there values;
  update_val(&values);
  values.setting=3;              //수정 전 setting 변수의 default 값
  double allc=allc_calc(values);
  while(1){
    menu(allc,values);
    int want;
    scanf(" %d",&want);
    switch(want){
      case 1:{
        printf("확률의 총합은 %lf이다.\n",sum_prob(allc,values));
        back_to_startline();
      }
      break;
      case 2:{
        printf("평균값은 %lf이다.\n",avr(allc,values));
        back_to_startline();
      }
      break;
      case 3:{
        double h=dispersion(allc,values);
        printf("분산값은 %lf이다.\n",h);
        printf("표준편차의 값은 %lf이다.\n",sqrt(h));
        back_to_startline();
      }
      break;
      case 4:{
        update_val(&values);
        allc=allc_calc(values);
        back_to_startline();
      }
      break;
      case 5:{
        update_setting(&values);
        back_to_startline();
      }break;
      case 6:{
        system("cls");
        display(allc,values);
        back_to_startline();
      }break;
      case 0:{
        return 0;
      }break;
      default:{
        printf("잘못된 입력값입니다. 다시 입력해주십시오\n");
        back_to_startline();
      }
      break;
    }
  }
}
//---------------------------------함수 전문----------------
void menu(double allc,there values){
  printf("table\t|%.0lf\n",values.table);
  printf("goal\t|%d\n",values.goal);
  printf("count\t|%d\n",values.count);
  printf("%.20lf=allc\n\n",allc);
  printf("종료는 0번\n\n");
  printf("확률의 총합을 구하고 싶다면 1번, 평균값을 구하고 싶다면 2번, 분산 및 표준편차를 구하고 싶다면 3번을,\n\n");
  printf("테이블,목표,확인범위 값을 수정하고 싶다면 4번을 입력하십시오\n\n");
  printf("출력 설정을 수정하고 싶다면 5번을 입력하십시오\n\n");
  printf("직접 돌아가는 걸 보고싶다면 6번을 입력하십시오:\n------------------------------------------");
}

void update_val(there*values){
  double a;
  int b,c;
  printf("\n전체 테이블의 갯수:");
  scanf("%lf",&a);
  values->table=a;
  printf("목표 테이블의 갯수:");
  scanf("%d",&b);
  values->goal=b;
  printf("확인 범위:");
  scanf("%d",&c);
  values->count=c;
}

void update_setting(there* values){
  int a;
  while(1){
    printf("\ncalc_save값의 변화를 출력하고 싶다면 1번, 결과값의 변화만을 출력하고 싶다면 2번,\n\n");
    printf("오로지 최종결과값만을 출력하고싶다면 3번을 입력해주세요:");
    scanf(" %d",&a);
    if(a>=1&&a<=3){
      values->setting=a;
      return;
    }
    else{
      printf("잘못된 입력값입니다. 다시 입력해주세요");
      int zz;
      scanf(" %d",&zz);
      system("cls");
    }
  }
}

double allc_calc(there values){
  double mid=1;
  for(int a=values.table;a>(values.table-values.goal);a--){
    mid *=(1/values.table)*a;
  }
  return mid;
}


here* var_init(there values){
  here *savedata;
  savedata = calloc(values.goal-1,sizeof(here)); //savedata 형식의 here[8]개;
  if(savedata != NULL){
    for(int a=1;a<values.goal;a++){      //1부터 8까지
      (savedata+a-1)->depth=1;        //depth의 초기 값을 1로 초기화
    }
    for(int a=1;a<values.goal;a++){      //0부터 7까지
      (savedata+a-1)->progress=a;   //savedata[0].progress==1, savedata[1].progress==2......savedata[7]=8
      for(double b=a;b<values.goal;b++){     //1부터 goal-1까지 (맞음)
        (savedata+a-1)->calc_save += (1/values.table)*b; //(1~8) (2~8) (3~8)....
      }
      //printf("%d//%lf\n",a-1,(savedata+a-1)->calc_save);
    }
  }
  return savedata;
}

void back_to_startline(){
  char check;
  printf("새로 구하고자 한다면 any키를 입력하시오");
  scanf(" %c",&check);
  system("cls");
}

double sum_prob(double allc,there values){
  double e=allc;
  here*savedata = var_init(values);
  for(int a=1;a<=values.count;a++){
    e+=allc*var_calc(a,savedata,values);
    if(values.setting==2){
      printf("%d번 뒤집기 전에 완료할 확률:%lf\n",values.goal+a,e);
    }
  }
  free(savedata);
  return e;
}
double avr(double allc,there values){
  double e=allc*values.goal;
  here*savedata = var_init(values);
  for(int a=1;a<=values.count;a++){
    e+=(values.goal+a)*allc*var_calc(a,savedata,values);
    if(values.setting==2){
      printf("%d번까지의 평균의 합:%lf\n",values.goal+a,e);
    }
  }
  free(savedata);
  return e;
}
double dispersion(double allc,there values){
  double e=allc*pow(allc,2);
  here*savedata = var_init(values);
  for(int a=1;a<=values.count;a++){
    e+=pow((values.goal+a),2)*allc*var_calc(a,savedata,values);
    if(values.setting==2){
      printf("%d번까지의 편차의 제곱의 합:%lf\n",values.goal+a,e);
    }
  }
  printf("--------------------\n");
  free(savedata);
  e-=pow(avr(allc,values),2);
  return e;
}
double var_calc(int a,here*savedata,there values){   //맨 처음 시작할때, savedata에는 depth 1부터 시작한다.
  if(a==1){             //a==savedata의 depth=1일때
    return savedata->calc_save;
  }
  else{       //a가 3이라면, 맨 처음 들어올때 savedat의 dapth값은 2이다. 즉 먼저 이 depth의 값을 3으로 올려준 다음에 depth3의 값을 전부 합해준다
    for(int b=1;b<values.goal;b++){
      double e=0;
      for(int c=b;c<values.goal;c++){
        e += (1/values.table)*c*(savedata+c-1)->calc_save;
      }
      (savedata+b-1)->calc_save=e;
      (savedata+b-1)->depth++;  //전부 완료되면 a==depth가 된다.
      if(values.setting==1){
        printf("%lf,%d,%d\n",(savedata+b-1)->calc_save,(savedata+b-1)->depth,(savedata+b-1)->progress);
      }
    }
    if(values.setting==1){
      printf("---------------------\n");
    }
    return savedata->calc_save;
  }
}

void display(double allc,there values){
  srand(time(0));
  int room[10][10]={{0}};
  int a,b;
  int count=0;
  int tap=0;
  while(1){
    a=(rand()%10);
    b=(rand()%10);
    room[a][b]=1;
    tap++;
    printf("  1 2 3 4 5 6 7 8 9 10\n1 ");
    for(int x=0;x<10;x++){
      for(int y=0;y<10;y++){
        printf("%d ",room[x][y]);
        if(room[x][y]==1){
          count++;
        }
      }
      printf("\n%d ",x+2);
      if(x == 8){
        printf("\r0 ");
      }
      else if(x==9){
        printf("\r");
      }
    }
    printf("시행수는 %d번\n",tap);
    printf("1의 개수는 %d개\n",count);

    if(count >= 90){
      printf("종료!\n");
      printf("총 시행 횟수 : %d\n",tap);
      if(values.table==100 && values.goal==90){
        printf("시행수 평균:%lf\n",avr(allc,values));
        printf("상위:%lf 퍼센트\n",100*tap_prob(allc,values,tap));
      }
      return;
    }
    count = 0;
    system("cls");
  }
}
double tap_prob(double allc,there values,int tap){
  double e=allc;
  here*savedata = var_init(values);
  for(int a=1;a<=tap-values.goal;a++){
    e+=allc*var_calc(a,savedata,values);
  }
  free(savedata);
  return e;
}
/*a=1일때 depth1의 모든 progress의 합을 출력한다.
  a=2일때 depth2의 모든 progress의 합


double var_calc(int depth,double progress,here*savedata){
  double res=0;
    for(;progress<goal;progress++){
      res += (progress/(goal+1)) * savedata[progress].calc_save;//var_calc(depth-1,progress);  //깊이 3, 진행 2라면
    }
  return res;
}
*/
