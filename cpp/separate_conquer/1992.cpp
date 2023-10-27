#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int divide(int x,int y,int depth,int** arr){
	if(!depth){
		return arr[x][y];
	}
	else{
		int ck4[4];
		ck4[0]=divide(x,y,depth-1,arr);
		ck4[1]=divide(x+(1<<(depth-1)),y,depth-1,arr);
		ck4[2]=divide(x,y+(1<<(depth-1)),depth-1,arr);
		ck4[3]=divide(x+(1<<(depth-1)),y+(1<<(depth-1)),depth-1,arr);
		int sum = ck4[0]+ck4[1]+ck4[2]+ck4[3];
		if(!sum){
			return 0;
		}
		else if(sum<4){
			for(int a=0;a<4;a++){
				if(ck4[a]==1){
					cout<<1;
				}
				else if(!ck4[a]){
					cout<<0;
				}
				else{
					
				}
			}
			return -4;
		}
		else{
			return 1;
		}
	}
}

int main(){
	int n,input;
	cin>>n;
	int** arr = new int*[n]; 
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
		memset(arr[i],0,sizeof(arr[i]));
	}
	cin.get();
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			arr[a][b] = cin.get()-48;
		}
		cin.get();
	}
	int last = divide(0,0,log2(n),arr);
	cout<<'(';
	if(!last){
		cout<<0;
	}
	else if(last==1){
		cout<<1;
	}
	cout<<')';
	for(int a=0;a<n;a++){
		delete[] arr[a];
	}
	delete[] arr;
}

/*
	cout<<"-----------------"<<endl;
	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			cout<<(arr[a]>>b)%2<<" ";
		}
		cout<<endl;
	}
	cout<<"-----------------"<<endl;
*/