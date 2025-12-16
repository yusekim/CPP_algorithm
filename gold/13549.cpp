#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K;
queue<int> que;
vector<int> vec(100001, 100001);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	if (N == K)
	{
		cout << 0 <<'\n';
		return 0;
	}
	vec[N] = 0;
	que.push(N);
	while (que.size())
	{
		int val = que.front();
		que.pop();
		if (val * 2 < vec.size() && vec[val * 2] > vec[val] + 1)
		{
			vec[val * 2] = vec[val];
			que.push(val * 2);
		}
		if (val - 1 >= 0 && vec[val - 1] > vec[val] + 1)
		{
			vec[val - 1] = vec[val] + 1;
			que.push(val - 1);
		}
		if (val + 1 < vec.size() && vec[val + 1] > vec[val] + 1)
		{
			vec[val + 1] = vec[val] + 1;
			que.push(val + 1);
		}
	}
	cout << vec[K] << '\n';
}
