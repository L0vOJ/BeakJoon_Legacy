#include <iostream>

class stack{
private:
  int* arr;
  int m_size;
public:
  stack();
  int pop();
  void push(int input);
  int size();
  int empty();
  int top();
};

stack::stack(){
  arr = new int;
  m_size=0;
}
int stack::pop(){
  if(!m_size){
    return -1;
  }
  int remain = arr[m_size-1];
  m_size--;
  if(!m_size){
    delete[] arr;
    return remain;
  }
  else{
    arr = (int*)realloc(arr,m_size*sizeof(int));
  }
  return remain;
}
void stack::push(int input){
  m_size++;
  if(m_size == 1){
    arr = (int*)malloc(sizeof(int));
  }
  else{
    arr = (int*)realloc(arr,m_size*sizeof(int));
  }
  arr[m_size-1] = input;
}
int stack::size(){
  return m_size;
}
int stack::empty(){
  if(m_size){
    return 0;
  }
  else{
    return 1;
  }
}
int stack::top(){
  if(!m_size){
    return -1;
  }
  else{
    return arr[m_size-1];
  }
}

int main(){
  stack here;
  int memory[100001];
  int n,num,doo=0;
  char say[10];
  std::cin>>n;
  for(int a=0;a<n;a++){
    std::cin >> say;
    //std::cout << say << std::endl;
    if(say[0]=='p'&&say[1]=='u'){ //push
      std::cin >> num;
      here.push(num);
    }
    else if(say[0]=='p'&&say[1]=='o'){  //pop
      memory[doo] = here.pop();
      doo++;
    }
    else if(say[0]=='s'){ //size
      memory[doo] = here.size();
      doo++;
    }
    else if(say[0]=='e'){  //empty
      memory[doo] = here.empty();
      doo++;
    }
    else if(say[0]=='t'){    //top
      memory[doo] = here.top();
      doo++;
    }
    else{
      std::cout << "error" <<std::endl;
    }
  }
  for(int a=0;a<doo;a++){
    std::cout << memory[a] << std::endl;
  }
  return 0;
}
