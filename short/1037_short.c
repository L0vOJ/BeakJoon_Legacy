#include<stdio.h>
int main(){int n,f,l=1,b;scanf("%d %d",&n,&f);for(int a=1;a<n;a++){scanf("%d",&b);if(b<f){if(l==1){l=f;}f=b;}else if(b>l){l=b;}}if(n==1){printf("%d",f*f);return 0;}printf("%d",f*l);}
