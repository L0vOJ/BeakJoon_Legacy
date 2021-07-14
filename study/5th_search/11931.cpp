#include<iostream>
#include<algorithm>
using namespace std;
bool desc(int a, int b){
  return a > b;
}

int main(){
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int z=0;z<n;z++){
    scanf("%d",&arr[z]);
  }
  sort(arr,arr+n,desc);
  for(int z=0;z<n;z++){
    printf("%d\n",arr[z]);
  }
  delete arr;
}
