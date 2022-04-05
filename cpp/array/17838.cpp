#include<iostream>
using namespace std;
int main(){
	string input;
	int arr[6] = {1,4,2,3,5,6};
	int n,check;
	char cmp;
	cin>>n;
	for(int z=0;z<n;z++){
		cin>>input;
		cmp = input.at(0);
		check=1;
		if(input.size()==7){
			for(int a=0;a<6;a++){
				if(a==2){
					if(cmp==input.at(arr[a])) {check=0;break;}
					else cmp = input.at(arr[a]);
				}
				else{
					if(cmp!=input.at(arr[a])) {check=0;break;}
				}
			}
			if(check) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else cout<<0<<endl;
	}
}