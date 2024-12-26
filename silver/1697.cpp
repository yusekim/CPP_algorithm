#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> que;

void bfs(int N, int K, vector<int> &vec)
{
	while(vec[K] == 0 && que.size())
	{
		int val = que.front();
		que.pop();
		if (val - 1 >= 0 && vec[val - 1] == 0)
		{
			vec[val - 1] = vec[val] + 1;
			que.push(val - 1);
		}
		if (val + 1 < vec.size() && vec[val + 1] == 0)
		{
			vec[val + 1] = vec[val] + 1;
			que.push(val + 1);
		}
		if (val * 2 < vec.size() && vec[val * 2] == 0)
		{
			vec[val * 2] = vec[val] + 1;
			que.push(val * 2);
		}
	}
	cout << vec[K] << '\n';
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	if (N == K)
	{
		cout << 0 << '\n';
		return 0;
	}
	vector<int> vec(100001, 0);
	que.push(N);
	bfs(N, K, vec);
}
