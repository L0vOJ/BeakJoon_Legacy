#include <array>
#include<iostream>
using namespace std;
typedef array<int,101> myarr;
int main(){
	myarr arr = {};
	int m,n,sum,input,output;
	cout << fixed;
	cout.precision(3);
	cin>>m;
	for(int a=0;a<m;a++){
		cin>>n;
		arr.fill(0);
		sum=0;
		output=0;
		for(int b=0;b<n;b++){
			cin>>input;
			arr.at(input)++;
			sum+=input;
		}
		for(int c=sum/n+1;c<=100;c++){
			output+=arr.at(c);
		}
		cout<<float(output)/float(n)*100<<"%"<<endl;
	}
}