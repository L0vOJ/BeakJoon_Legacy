#include<stdio.h>
#include<stdlib.h>  //���� �Ҵ� ����
#include<string.h>
#include<time.h>
#include<math.h>
#include<stddef.h>  //sizeof ������ ����
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
//----------------�Լ�
void update_val(there*);
void update_setting(there*);

double allc_calc(there);  //���⼭ allc�� all Clear(�ߺ� ���� �ѹ��� ��ǥ���� ������ Ȯ��)�̴�.
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
  values.setting=3;              //���� �� setting ������ default ��
  double allc=allc_calc(values);
  while(1){
    menu(allc,values);
    int want;
    scanf(" %d",&want);
    switch(want){
      case 1:{
        printf("Ȯ���� ������ %lf�̴�.\n",sum_prob(allc,values));
        back_to_startline();
      }
      break;
      case 2:{
        printf("��հ��� %lf�̴�.\n",avr(allc,values));
        back_to_startline();
      }
      break;
      case 3:{
        double h=dispersion(allc,values);
        printf("�л갪�� %lf�̴�.\n",h);
        printf("ǥ�������� ���� %lf�̴�.\n",sqrt(h));
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
        printf("�߸��� �Է°��Դϴ�. �ٽ� �Է����ֽʽÿ�\n");
        back_to_startline();
      }
      break;
    }
  }
}
//---------------------------------�Լ� ����----------------
void menu(double allc,there values){
  printf("table\t|%.0lf\n",values.table);
  printf("goal\t|%d\n",values.goal);
  printf("count\t|%d\n",values.count);
  printf("%.20lf=allc\n\n",allc);
  printf("����� 0��\n\n");
  printf("Ȯ���� ������ ���ϰ� �ʹٸ� 1��, ��հ��� ���ϰ� �ʹٸ� 2��, �л� �� ǥ�������� ���ϰ� �ʹٸ� 3����,\n\n");
  printf("���̺�,��ǥ,Ȯ�ι��� ���� �����ϰ� �ʹٸ� 4���� �Է��Ͻʽÿ�\n\n");
  printf("��� ������ �����ϰ� �ʹٸ� 5���� �Է��Ͻʽÿ�\n\n");
  printf("���� ���ư��� �� ����ʹٸ� 6���� �Է��Ͻʽÿ�:\n------------------------------------------");
}

void update_val(there*values){
  double a;
  int b,c;
  printf("\n��ü ���̺��� ����:");
  scanf("%lf",&a);
  values->table=a;
  printf("��ǥ ���̺��� ����:");
  scanf("%d",&b);
  values->goal=b;
  printf("Ȯ�� ����:");
  scanf("%d",&c);
  values->count=c;
}

void update_setting(there* values){
  int a;
  while(1){
    printf("\ncalc_save���� ��ȭ�� ����ϰ� �ʹٸ� 1��, ������� ��ȭ���� ����ϰ� �ʹٸ� 2��,\n\n");
    printf("������ ������������� ����ϰ�ʹٸ� 3���� �Է����ּ���:");
    scanf(" %d",&a);
    if(a>=1&&a<=3){
      values->setting=a;
      return;
    }
    else{
      printf("�߸��� �Է°��Դϴ�. �ٽ� �Է����ּ���");
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
  savedata = calloc(values.goal-1,sizeof(here)); //savedata ������ here[8]��;
  if(savedata != NULL){
    for(int a=1;a<values.goal;a++){      //1���� 8����
      (savedata+a-1)->depth=1;        //depth�� �ʱ� ���� 1�� �ʱ�ȭ
    }
    for(int a=1;a<values.goal;a++){      //0���� 7����
      (savedata+a-1)->progress=a;   //savedata[0].progress==1, savedata[1].progress==2......savedata[7]=8
      for(double b=a;b<values.goal;b++){     //1���� goal-1���� (����)
        (savedata+a-1)->calc_save += (1/values.table)*b; //(1~8) (2~8) (3~8)....
      }
      //printf("%d//%lf\n",a-1,(savedata+a-1)->calc_save);
    }
  }
  return savedata;
}

void back_to_startline(){
  char check;
  printf("���� ���ϰ��� �Ѵٸ� anyŰ�� �Է��Ͻÿ�");
  scanf(" %c",&check);
  system("cls");
}

double sum_prob(double allc,there values){
  double e=allc;
  here*savedata = var_init(values);
  for(int a=1;a<=values.count;a++){
    e+=allc*var_calc(a,savedata,values);
    if(values.setting==2){
      printf("%d�� ������ ���� �Ϸ��� Ȯ��:%lf\n",values.goal+a,e);
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
      printf("%d�������� ����� ��:%lf\n",values.goal+a,e);
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
      printf("%d�������� ������ ������ ��:%lf\n",values.goal+a,e);
    }
  }
  printf("--------------------\n");
  free(savedata);
  e-=pow(avr(allc,values),2);
  return e;
}
double var_calc(int a,here*savedata,there values){   //�� ó�� �����Ҷ�, savedata���� depth 1���� �����Ѵ�.
  if(a==1){             //a==savedata�� depth=1�϶�
    return savedata->calc_save;
  }
  else{       //a�� 3�̶��, �� ó�� ���ö� savedat�� dapth���� 2�̴�. �� ���� �� depth�� ���� 3���� �÷��� ������ depth3�� ���� ���� �����ش�
    for(int b=1;b<values.goal;b++){
      double e=0;
      for(int c=b;c<values.goal;c++){
        e += (1/values.table)*c*(savedata+c-1)->calc_save;
      }
      (savedata+b-1)->calc_save=e;
      (savedata+b-1)->depth++;  //���� �Ϸ�Ǹ� a==depth�� �ȴ�.
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
    printf("������� %d��\n",tap);
    printf("1�� ������ %d��\n",count);

    if(count >= 90){
      printf("����!\n");
      printf("�� ���� Ƚ�� : %d\n",tap);
      if(values.table==100 && values.goal==90){
        printf("����� ���:%lf\n",avr(allc,values));
        printf("����:%lf �ۼ�Ʈ\n",100*tap_prob(allc,values,tap));
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
/*a=1�϶� depth1�� ��� progress�� ���� ����Ѵ�.
  a=2�϶� depth2�� ��� progress�� ��


double var_calc(int depth,double progress,here*savedata){
  double res=0;
    for(;progress<goal;progress++){
      res += (progress/(goal+1)) * savedata[progress].calc_save;//var_calc(depth-1,progress);  //���� 3, ���� 2���
    }
  return res;
}
*/
