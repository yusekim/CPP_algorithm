#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>> &tree, int start, vector<bool> &visited)
{
	vector<int> stk;
	stk.push_back(start);
	while (!stk.empty())
	{
		int val = stk.back();
		stk.pop_back();
		if (!visited[val])
		{
			cout << val + 1 << ' ';
			visited[val] = true;
			for (int i = tree[val].size() - 1; i >= 0; i--)
			{
				int next = tree[val][i];
				if (!visited[next])
					stk.push_back(next);
			}
		}
	}
	cout << '\n';
}

void bfs(const vector<vector<int>> &tree, int start, vector<bool> &visited)
{
	queue<int> que;
	que.push(start);
	while (!que.empty())
	{
		int val = que.front();
		que.pop();
		if (!visited[val])
		{
			cout << val + 1 << ' ';
			visited[val] = true;
			for (int next : tree[val])
			{
				if (!visited[next])
					que.push(next);
			}
		}
	}
	cout << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, v;
	cin >> n >> m >> v;
	vector<vector<int>> tree(n);
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		tree[from - 1].push_back(to - 1);
		tree[to - 1].push_back(from - 1);
	}
	for (int i = 0; i < n; i++)
		sort(tree[i].begin(), tree[i].end());

	vector<bool> visited(n, false);
	dfs(tree, v - 1, visited);
	fill(visited.begin(), visited.end(), false);
	bfs(tree, v - 1, visited);
}
