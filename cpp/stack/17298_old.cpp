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
    if(remain.empty() || remain.top()>=input.front()){          //remain�� ���ų� �տ� ��ū���� ����
      remain.push(input.front());                               //remain�� ���
      printf("in-re %d\n",remain.top());
      input.pop();
    }
    else{
      while(remain.top()<input.front()){                        //�Է¹��� ���� ���ڰ� remain�� ����Ǿ��ִ� top ������ ũ��
        if(!remain.empty()){                                    //remain�� ���� �������� ��
          if(remain.size()==left){                               //���� ���� �Ϳ� ��������
            while(remain.top()!=-1){                             //�̹� ��ū�� ������ �ִ°� buffer�� ���ǽ�Ű��
              buffer.push(streak.top());
              remain.pop();
              streak.top();
              left--;
            }                                                 //���ǰ� ������ -1 ����� �� �ڸ��� ��ū�� �� �ֱ�
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
      while(!streak.empty()){               //output�� �ֱ� ���� ������ ��Ƴ��� ���� -1�� �ο��ؾ��Ѵ�
        output.push(streak.top());          //-1�ο��� �� 2�����׸� �ο��� �� ������, �߰��� ���� ū��� ������ ���̴�
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
