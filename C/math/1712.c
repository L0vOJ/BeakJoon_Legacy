#include <stdio.h>
int main(){
  int t=0,a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  if(b>=c){
    printf("-1\n");
  }
  else printf("%d",(a/(c-b))+1);
}
