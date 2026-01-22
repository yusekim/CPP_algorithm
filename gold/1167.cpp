#include <iostream>
#include <vector>
using namespace std;
int v, dist, ret;
vector<vector<pair<int, int>>> tree(100001);

void dfs_rec(vector<bool> &visited, vector<int> &res, int s)
{
	visited[s] = true;
	for (auto [n, w] : tree[s])
	{
		if (visited[n] == false)
		{
			int n_node = n;
			int n_dist = res[s] + w;
			if (n_dist > res[n_node])
			{
				res[n_node] = n_dist;
				if (n_dist > dist)
				{
					dist = n_dist;
					ret = n_node;
				}
			}
			dfs_rec(visited, res, n_node);
		}
	}
}

void dfs(int start)
{
	vector<bool> visited(v + 1, false);
	vector<int> res(v + 1, 0);
	dist = 0;
	ret = start;
	dfs_rec(visited, res, start);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		int cur, dest, w;
		cin >> cur >> dest;
		while (dest != -1)
		{
			cin >> w;
			tree[cur].push_back({dest, w});
			cin >> dest;
		}
	}
	dfs(1);
	dfs(ret);
	cout << dist << '\n';
}
