#include <stdio.h>
int main(){
	int arr[42]={0};
	int input,output=0;
	for(int a=0;a<10;a++){
		scanf("%d",&input);
		arr[input%42]=1;
	}
	for(int a=0;a<42;a++){
		output+=arr[a];
	}
	printf("%d",output);
}