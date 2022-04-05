#include<iostream>
using namespace std;
int main(){
	int m,a,b,comp;
	int table[5] = {1,1,4,4,2};
	cin>>m;
	for(int z=0;z<m;z++){
		cin>>a>>b;
		comp=a;
		for(int x=0;x<(b-1)%table[a%5];x++){
			comp*=a;
		}
		if(comp%10) cout<<comp%10<<endl;
		else cout<<10<<endl;
	}
}