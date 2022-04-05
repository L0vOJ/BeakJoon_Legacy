#include <stdio.h>
int main(){
	int arr[101]={0};
	int n,input;
	float sum=0;
	scanf("%d",&n);
	for(int a=0;a<n;a++){
		scanf("%d",&input);
		arr[input]=1;
		sum+=input;
	}
	for(int a=100;a>0;a--){
		if(arr[a]){
			printf("%f",sum/a*100/n);
			return 0;
		}
	}
}