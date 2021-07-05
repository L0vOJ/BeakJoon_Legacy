#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< pair<int, int> > v;
// 회의가 끝나는 시간을 기준으로 오름차순 정렬
bool compare (pair<int, int> a, pair<int, int> b)
{
	if(a.second==b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		int start, finish;
		cin >> start >> finish;
		v.push_back(make_pair(start, finish));
	}

	sort(v.begin(), v.end(), compare);

	int time = v[0].second;
	int cnt = 1;
	for (int i = 1;i < n;i++)
	{
		if (time <= v[i].first)
		{
			time = v[i].second;
			cnt++;
		}
	}
	cout << cnt << '\n';
}
