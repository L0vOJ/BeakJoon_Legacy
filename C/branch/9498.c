#include <stdio.h>
int main(){
	int input;
	scanf("%d",&input);
	if(input>=90) printf("A");		
	else if(input>=80) printf("B");
	else if(input>=70) printf("C");
	else if(input>=60) printf("D");
	else printf("F");
}