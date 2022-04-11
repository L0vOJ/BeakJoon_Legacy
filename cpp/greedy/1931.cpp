#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	int i1,i2;
	cin>>n;
	vector<pair<int,int>> schedule(n);
	for(int a=0;a<n;a++){
		cin>>i1>>i2;
		schedule[a] = make_pair(i2,i1);
	}
	sort(schedule.begin(),schedule.end());
	int stack=1;
	int checkpoint=0;
	for(int a=1;a<n;a++){
		if(schedule[checkpoint].first<=schedule[a].second){
			stack++;
			checkpoint = a;
		}
	}
	cout<<stack;
}