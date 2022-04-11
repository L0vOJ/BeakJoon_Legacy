#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main(){
	vector<int> v(10001);
	fill(v.begin()+2,v.end(),1);
	for(int a=2;a<100;a++){
		if(v[a]){
			for(int b=2*a;b<10001;b+=a){
				v[b]=0;
			}
		}
	}
	for(int c=0;c<10001;c++){
		if(v[c]) cout<<c<<",";
	}
}