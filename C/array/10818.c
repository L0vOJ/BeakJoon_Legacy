#include <stdio.h>
int main(){
	int array[2000001] = {0};
	int n,input,checkF=1,checkL=1,first,last;
	scanf("%d",&n);
	for(int a=0;a<n;a++){
		scanf("%d",&input);
		array[input+1000000]=1;
	}
	for(int a=0;a<2000001;a++){
		if(array[a]){
			if(checkF){
				checkF=0;
				first = a-1000000;
			}
			else{
				checkL=0;
				last = a-1000000; 
			}
		}
	}
	if(checkL){
		last = first;
	}
	printf("%d %d",first,last);
}