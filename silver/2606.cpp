#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M, a, b, res = -1;

	cin >> N >> M;
	vector<vector<int> > vec(N + 1);
	while (M--)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vector<bool> visited(vec.size(), false);
	stack<int> next;

	next.push(1);
	while (!next.empty())
	{
		int tmp = next.top();
		next.pop();
		if (visited[tmp] == false)
		{
			res++;
			visited[tmp] = true;
			for (auto it = vec[tmp].begin(); it != vec[tmp].end(); it++)
				next.push(*it);
		}
	}
	cout << res << '\n';
}
