#include<stdio.h>
int gcd(int a, int b){
	return b?gcd(b,a%b):a;
}
int main(){
  int n,f,b,s;
  scanf("%d %d",&n,&f);
  for(int a=1;a<n;a++){
    scanf("%d",&b);
    s=gcd(f,b);
    printf("%d/%d\n",f/s,b/s);
  }
}
