#include<stdio.h>
#include<math.h>
int main(){
  int f,l,output=0;
  int arr[80000];
  int lay=0;
  scanf("%d %d",&f,&l);
  for(f;f<=l;f++){
    int stop=0;
    for(int a=2;a<=sqrt(f);a++){
      if(f%a==0){
        stop=1;
        break;
      }
    }
    if(stop==1){
      continue;
    }
    arr[lay] = f;
    lay++;
  }
  for(int z=0;z<lay;z++){
    if(arr[z]==1){
      continue;
    }
    printf("%d\n",arr[z]);
  }
}
