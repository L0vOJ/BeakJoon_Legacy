#include<stdio.h>
int main(){
  int n,first,last=1,buffer;
  scanf("%d %d",&n,&first);
  for(int a=1;a<n;a++){
    scanf("%d",&buffer);
    if(buffer<first){
      if(last==1){
        last=first;
      }
      first = buffer;
    }
    else if(buffer>last){
      last = buffer;
    }
  }
  if(n==1){
    printf("%d",first*first);
    return 0;
  }
  printf("%d",first*last);
}
