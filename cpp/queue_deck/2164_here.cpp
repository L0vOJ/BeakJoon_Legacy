#include <iostream>
#include <queue>
using namespace std;
int main() {
  queue<int> q;
	int n;
	cin >> n;
  for(int a=1;a<=n;a++){
    q.push(a);
  }
	while(q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}
