#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct status{
  string name;
  int a,b,c;
}student[100001];

bool standard(status s1, status s2){
  if(s1.a != s2.a){
    return s1.a > s2.a;
  }
  else if(s1.b != s2.b){
    return s1.b < s2.b;
  }
  else if(s1.c != s2.c){
    return s1.c > s2.c;
  }
  else
    return s1.name < s2.name;
};


int main(){
  int n;
  cin>>n;
  for(int z=0;z<n;z++){
    //cin>>student[z].name>>student[z].a>>student[z].b>>student[z].c;
    cin>>student[z].name;
    scanf("%d %d %d",&student[z].a,&student[z].b,&student[z].c);
  }
  //printf("hello\n");
  sort(student,student+n,standard);
  for(int z=0;z<n;z++){
    cout<<student[z].name<<"\n";  //string에 printf를 적용 못한다고 해도, endl가 가장 많은 시간을 잡아먹으므로 endl만 빼주면 얼추 된 그것만 안쓰면 됨
  }
}
