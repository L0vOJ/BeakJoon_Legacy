#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
  queue<int> input;
  stack<int> remain;
  stack<int> streak;
  stach<int> buffer;
  queue<int> output;
  queue<int> routput;
  int n,get;
  int left=0;
  cin>>n;
  for(int a=0;a<n;a++){
    scanf("%d",&get);
    input.push(get);
  }
  while(!input.empty()){
    if(remain.empty() || remain.top()>=input.front()){          //remain이 없거나 앞에 오큰수가 없을
      remain.push(input.front());                               //remain에 담기
      printf("in-re %d\n",remain.top());
      input.pop();
    }
    else{
      while(remain.top()<input.front()){                        //입력받을 다음 숫자가 remain에 저장되어있는 top 값보다 크면
        if(!remain.empty()){                                    //remain에 무언가 남아있을 때
          if(remain.size()==left){                               //고여서 남은 것에 도달했을
            while(remain.top()!=-1){                             //이미 오큰수 정해져 있는거 buffer로 대피시키기
              buffer.push(streak.top());
              remain.pop();
              streak.top();
              left--;
            }                                                 //대피가 끝나면 -1 지우고 그 자리에 오큰수 값 넣기
          }
          remain.pop();
          while(!buffer.empty()){
            stack.push(buffer.top());
            buffer.pop();
          }
          stack.push(input.front());
          printf("re-st %d\n",streak.top());
        }
        if(remain.empty()){
          break;
        }
      }
      if(remain.size()-left>0){
        while(remain.size()>left){
          streak.push(-1);
          left++;
        }
      }
      while(!streak.empty()){               //output에 넣기 전에 끝까지 살아남은 놈은 -1을 부여해야한다
        output.push(streak.top());          //-1부여는 단 2놈한테만 부여할 수 있으며, 중간에 가장 큰놈과 마지막 놈이다
        printf("st-op %d\n",output.back());
        streak.pop();
      }
      if(remain.empty()){
        while(!output.empty()){
          routput.push(output.front());
          output.pop();
        }
      }
    }
  }
  if(!remain.empty()){
    routput.push(-1);
    remain.pop();
    while(!output.empty()){
      routput.push(output.front());
      output.pop();
    }
  }
  while(!routput.empty()){
    printf("%d ",routput.front());
    routput.pop();
  }
}
