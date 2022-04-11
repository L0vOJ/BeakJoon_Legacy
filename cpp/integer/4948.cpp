#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int main(){
	int n;
	int stack;
	while(true){
		cin>>n;
		if(n==0){
			break;
		}
		if(n==1){
			cout<<'1'<<endl;
			continue;
		}
		vector<int> v(n+1);
		fill(v.begin()+1,v.end(),1);
		for(int a = 2;a<=sqrt(2*n);a++){
			for(int b=-n%a;b<=n;b+=a){
				if(b<0) b+=a;
				v[b] = 0;
			}
		}
		stack=0;
		for(int c=0;c<=n;c++){
			stack+=v[c];
		}
		cout<<stack<<endl;
	}
}