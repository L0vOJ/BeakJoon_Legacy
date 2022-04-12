#include <iostream>
#include<bitset>
using namespace std;
int main(){
	int n1,n2,output=32;
	long long line;
	char text;
	cin>>n1>>n2;
	long long arr[n1];
	int comp1[2][n1][n2-7];
	int comp2[n1-7][n2-7];
	for(int a=0;a<n1;a++){
		line=0;
		for(int b=0;b<n2;b++){
			cin>>text;
			if(text=='W'||text=='w') line++;
			if(b<n2-1) line=line<<1;
		}
		arr[a]=line;
	}
	for(int a=0;a<n1;a++){
		for(int b=0;b<n2-7;b++){
			comp1[0][a][b] = (arr[a]>>(n2-8-b))&255^(85<<(a%2));
			comp1[1][a][b]=0;
			for(int c=0;c<8;c++) if((comp1[0][a][b]>>c)&1) comp1[1][a][b]++;
		}
	}
	for(int a=0;a<n1-7;a++){
		for(int b=0;b<n2-7;b++){
			comp2[a][b]=0;
			for(int c=0;c<8;c++) comp2[a][b]+=comp1[1][a+c][b];
			comp2[a][b] = (comp2[a][b]<64-comp2[a][b])?comp2[a][b]:64-comp2[a][b];
			output = (output<comp2[a][b])?output:comp2[a][b];
		}
	}
	cout<<output;
}