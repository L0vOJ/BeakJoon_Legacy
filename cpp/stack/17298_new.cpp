#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack<pair<int,int>> remain;
int *arr;
int n;
int main(){
  cin>>n;
  arr = (int*)calloc(n,sizeof(int));
  for(int a=0;a<n;a++){
    scanf("%d",&arr[a]);
  }
  remain.push(make_pair(0,arr[0]));
  for(int a=1;a<n;a++){
    while(remain.top().second < arr[a]){
      arr[remain.top().first] = arr[a];
      remain.pop();
      if(remain.empty()){
        break;
      }
    }
    remain.push(make_pair(a,arr[a]));
  }
  while(!remain.empty()){
    arr[remain.top().first] = -1;
    remain.pop();
  }
  for(int a=0;a<n;a++){
    printf("%d ",arr[a]);
  }
}
