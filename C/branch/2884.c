#include <stdio.h>
int main(){
	int input[2];
	scanf("%d %d",&input[0],&input[1]);
	if(input[1]>=45){
		printf("%d %d",input[0],input[1]-45);
	}
	else{
		if(input[0]==0) printf("23 %d",input[1]+15);
		else printf("%d %d",input[0]-1,input[1]+15);
	}
}