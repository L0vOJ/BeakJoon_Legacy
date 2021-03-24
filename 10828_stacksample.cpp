#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	stack <int> S;
	int n;
	cin>>n;
	while(n--){
		string c;
		cin>>c;
		if(c=="push"){
			int tmp;
			cin>>tmp;
			S.push(tmp);
		}else if(c=="pop"){
			if(S.empty())cout<<"-1\n";
			else{
				cout<<S.top()<<'\n';
				S.pop();
			}
		}else if(c=="size"){
			cout<<S.size()<<'\n';
		}else if(c=="empty"){
			cout<<S.empty()<<'\n';
		}else if(c=="top"){
			if(S.empty())cout<<"-1\n";
			else cout<<S.top()<<'\n';
		}
	}
}
