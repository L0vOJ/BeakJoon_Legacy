#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,col[3],point[2][3]={{0,0,0},{0,0,0}};
	cin>>n;
	for(int a=0;a<n;a++){
		cin>>col[0]>>col[1]>>col[2];
		if(a==0){
			for(int b=0;b<3;b++){
				point[0][b] = col[b];
			}
		}
		else{
			point[1][0] = min(point[0][1],point[0][2]) + col[0];
			point[1][1] = min(point[0][0],point[0][2]) + col[1];
			point[1][2] = min(point[0][0],point[0][1]) + col[2];
			for(int b=0;b<3;b++){
				point[0][b] = point[1][b];
			}
		}
	}
	cout<<min(min(point[0][0],point[0][1]),point[0][2]);
}