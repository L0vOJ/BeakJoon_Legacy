#include <iostream>
#include <queue>
using namespace std;
#define p(a,b) pair<int,int>((a),(b))
pair<int,int> x;
int main(){
  int n,a,b;
  cin>>n;
  priority_queue<pair<int,int>>,vector<pair<int,int>>,less<pair<int,int>>> pq;
  for(int a=0;a<n;a++){
    cin>>a>>b;
    pq.push_back(p(a,b));
  }
  while(!pq.empty()){
    cout<<pq.top();
    pq.pop();
  }
}
