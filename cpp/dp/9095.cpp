#include<iostream>
using namespace std;
int main(){
	int n,input;
	cin>>n;
	for(int a=0;a<n;a++){
		cin>>input;
		input-=4;
		int brr[4] = {1,2,4,7};
		for(int b=0;b<input;b++){
			brr[b%4]=brr[(b+1)%4]+brr[(b+2)%4]+brr[(b+3)%4];

		}
		cout<<brr[(input+3)%4]<<endl;
	}
}
