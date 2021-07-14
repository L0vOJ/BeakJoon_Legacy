#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct status{
  string name;
  int score[3];
};

bool standard(status a,status b){
  if(a.score[0] != b.score[0]){
    return a.score[0] > b.score[0];
  }
  else if(a.score[1] != b.score[1]){
    return a.score[1] < b.score[1];
  }
  else if(a.score[2] != b.score[2]){
    return a.score[2] > b.score[2];
  }
  else
    return strcmp(a.name,b.name);
}


int main(){
  int n;
  cin>>n;
  struct status student = new status[n];
  for(int z=0;z<n;z++){
    scanf("%s %d %d %d",&student[z].name,&student[z].score[0],&student[z].score[1],&student[z].score[2]);
  }
  sort(student,student+n,standard);
  for(int z=0;z<n;z++){
    printf("%s\n", student[z].name);
  }
}
