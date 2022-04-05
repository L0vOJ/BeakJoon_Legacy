#include <stdio.h>
int main(){
	int arr[100]={0};
	int input;
	for(int a=0;a<9;a++){
		scanf("%d",&input);
		arr[input]=a+1;
	}
	for(int a=99;a>=0;a--){
		if(arr[a]>0){
			printf("%d %d",a,arr[a]);
			return 0;
		}
	}
}