#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n,in1,in2;
	cin>>n;
	vector<pair<int,int>> data(n);
	vector<int> grade(n);
	fill(grade.begin(),grade.end(),1);
	for(int a=0;a<n;a++){
		cin>>in1>>in2;
		data[a] = make_pair(in1,in2);
		if(a){
			for(int b=0;b<a;b++){
				if(data[a].first>data[b].first&&data[a].second>data[b].second) grade[b]++;
				else if(data[a].first<data[b].first&&data[a].second<data[b].second) grade[a]++;
			}
		}
	}
	for(int c=0;c<n;c++){
		cout<<grade[c]<<" ";
	}
}