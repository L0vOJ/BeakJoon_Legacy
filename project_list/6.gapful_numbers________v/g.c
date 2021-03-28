#include<stdio.h>
#include<string.h>
int main(){
  char input[11];// 2,100,000,000(\0)  //10+1
  char div_str[3];
  int ed,er;
  int gap_num;
  printf("~~gapful_numbers~~\n");
  printf("integer(less then 2 billion):\n");
  scanf("%s",input);
  div_str[0]=input[0];
  div_str[1]=*(input+strlen(input)-1);
  div_str[2]='\0';
  ed=atoi(input);
  er=atoi(div_str);
  gap_num = ed % er;
  if(gap_num){
    printf("%s is not gapful_number\n",input);
  }
  else{
    printf("%s is gapful_number\n",input);
  }
  return 0;
}
