#include <iostream>
#include <queue>
using namespace std;
int main(){
  priority_queue<int,vector<int>,greater<int>> pq;
  int aa,bb;
  int n,input,output=0;
  cin>>n;
  for(int z=0;z<n;z++){
    cin>>input;
    pq.push(input);
  }
  while(pq.size() > 1){
    aa = pq.top();
    pq.pop();
    bb = pq.top();
    pq.pop();
    output += aa+bb;
    pq.push(aa+bb);
    //cout<<aa<<"+"<<bb<<"="<<aa+bb<<endl;
  }
  cout<<output;
}
