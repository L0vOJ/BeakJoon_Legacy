#include<stdio.h>
void back_to_startline();
int main(){
  while(1){
    double e=0;
    double table;
    double goal;

    printf("table:");
    scanf("%lf",&table);
    printf("goal:");
    scanf("%lf",&goal);
    for(double a=table;a>table-goal;a--){
      e+=(table/a);
    }
    printf("%lf\n",e);    //e=19.289683
    back_to_startline();
  }
}

void back_to_startline(){
  char check;
  printf("새로 구하고자 한다면 any키를 입력하시오");
  scanf(" %c",&check);
  system("cls");
}
