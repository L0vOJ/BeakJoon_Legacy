#include <stdio.h>
int main(){
	int input;
	scanf("%d",&input);
	if(input%4==0 && input%100!=0) printf("1");
	else if(input%400==0) printf("1");
	else printf("0");
}