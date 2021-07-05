#include <iostream>
#include <queue>
using namespace std;

struct cmp1{   //오름차순 1,2,3,4,5 <<--
  bool operator()(pair<int,int> t,pair<int,int> q){
    return t.first > q.first;
  }
};


struct cmp2{   //오름차순 1,2,3,4,5 <<--
  bool operator()(pair<int,int> t,pair<int,int> q){
    return t.second > q.second;
  }
};

int t=0;
int output=0;

int main(){
  priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> pq1;
  priority_queue<pair<int,int>,vector<pair<int,int>>,cmp2> pq2;
  int n,a,b;
  cin>>n;
  for(int z=0;z<n;z++){
    cin>>a>>b;
    pq1.push(make_pair(a,b));
  }
  while(!pq1.empty()){
    pq2.push(pq1.top());
    pq1.pop();
  }
  while(!pq2.empty()){
    if(pq2.top().first >= t){
      t = pq2.top().second;
      output++;
    }
    pq2.pop();
  }
  cout<<output;
}

//cout<<pq.top().first<<","<<pq.top().second<<endl;
