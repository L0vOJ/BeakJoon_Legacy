#include<iostream>
using namespace std;
int main(){
	string input;
	int n,output,ac;
	cin>>n;
	for(int a=0;a<n;a++){
		output=0;
		ac=0;
		cin>>input;
		for(int b=0;b<input.size();b++){
			if(input.at(b)=='O'){
				output += ++ac;
			}
			else{
				ac=0;
			}
		}
		cout<<output<<endl;
	}
}