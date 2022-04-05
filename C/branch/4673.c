#include <stdio.h>
int self(int f){
	return f + f/1000 + f%1000/100 + f%100/10 + f%10;
}
int main(){
	int pr;
	for(int a=1;a<10000;a++){
		printf("%d,",self(a));
	}
}
