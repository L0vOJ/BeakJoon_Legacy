#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool comp(string s1, string s2){
	return s1 > s2;	//string ���� ����
}
int main(){
	//���ڿ� �迭
	string sArr[5] = {"abc", "aa", "abcd", "aza", "bcda"};

	//sArr[0] ~ sArr[4], ���� �������� ����
	sort(sArr, sArr+5, comp);

	//���
	for(int i=0;i<5;++i){
		cout << sArr[i] << endl;
	}

	return 0;
}
