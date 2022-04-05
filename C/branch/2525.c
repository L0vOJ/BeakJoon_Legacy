#include <stdio.h>
int main(){
	int input[3];
	scanf("%d %d %d",&input[0],&input[1],&input[2]);
	input[0]+=input[2]/60;
	input[1]+=input[2]%60;
	if(input[1]>=60){
		input[0]++;
		input[1]-=60;
	}
	input[0]%=24;
	printf("%d %d",input[0],input[1]);
}