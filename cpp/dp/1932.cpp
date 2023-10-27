#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,input[501],point[2][501] = {0,},output=0;
	cin>>n;
	for(int a=0;a<n;a++){
		for(int b=0;b<=a;b++){
			cin>>input[b];
		}	
		if(a==0){
			point[0][0] = input[0];
		}
		else{
			point[1][0] = point[0][0] + input[0];
			for(int b=1;b<=a;b++){
				point[1][b] = max(point[0][b-1],point[0][b]) + input[b];
			}
			for(int b=0;b<=a;b++){
				point[0][b] = point[1][b];
			}
		}

	}
	for(int a=0;a<n;a++){
		output = max(output,point[0][a]);
	}
	cout<<output;
}