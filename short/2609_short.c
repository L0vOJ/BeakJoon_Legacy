#include<stdio.h>
#define b f>l?f:l
int main(){int f,l,a;scanf("%d %d",&f,&l);for(a=b;;a--){if(f%a==0&&l%a==0)break;}printf("%d\n",a);for(a=b;;a+=b){if(a%f==0 && a%l==0)break;}printf("%d",a);}
