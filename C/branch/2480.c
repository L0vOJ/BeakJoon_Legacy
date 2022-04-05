#include <stdio.h>
int main(){
	int input[3],coin=0,target,diff=0;
	scanf("%d %d %d",&input[0],&input[1],&input[2]);
	for(int a=0;a<3;a++){
		for(int b=0;b<3;b++){
			if(a>=b){
				continue;
			}
			else{
				if(input[a]==input[b]) {
					coin++;
					target = input[a];
				}
			}
		}
		diff = diff>=input[a]?diff:input[a];
	}
	if(coin==3) printf("%d",10000+target*1000);
	else if(coin==1) printf("%d",1000+target*100);
	else printf("%d",diff*100);
}