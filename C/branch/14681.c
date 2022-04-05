#include <stdio.h>
int main(){
	int input[2];
	scanf("%d %d",&input[0],&input[1]);
	if(input[0]>0){
		if(input[1]>0) printf("1");
		else printf("4");
	}
	else{
		if(input[1]>0) printf("2");
		else printf("3");
	}
}