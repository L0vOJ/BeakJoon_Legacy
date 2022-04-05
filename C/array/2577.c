#include <stdio.h>
int main(){
	int arr[10]={0};
	int input,comp=1;
	for(int a=0;a<3;a++){
		scanf("%d",&input);
		comp *= input;
	}
	while(1){
		arr[comp%10]++;
		if(comp<10){
			break;
		}
		else{
			comp/=10;
		}
	}
	for(int a=0;a<10;a++){
		printf("%d\n",arr[a]);
	}
}