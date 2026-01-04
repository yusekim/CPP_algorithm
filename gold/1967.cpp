#include <iostream>
#include <vector>
using namespace std;
int n, dist, ret;

void dfs_rec(vector<vector<pair<int, int>>> &tree, vector<bool> &visited, vector<int> &res, int s)
{
	visited[s] = true;
	for (const auto &edge : tree[s])
	{
		if (visited[edge.first] == false)
		{
			int next_node = edge.first;
			int next_dist = res[s] + edge.second;
			if (next_dist > res[next_node])
			{
				res[next_node] = next_dist;
				if (next_dist > dist)
				{
					dist = next_dist;
					ret = next_node;
				}
			}
			dfs_rec(tree, visited, res, next_node);
		}
	}
}

void dfs(vector<vector<pair<int, int>>> &tree, int start)
{
	vector<bool> visited(n + 1, false);
	vector<int> res(n + 1, 0);
	dist = 0;
	ret = start;
	dfs_rec(tree, visited, res, start);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<vector<pair<int, int>>> tree(n + 1);
	for (int i = 1; i < n; i++)
	{
		int pn, cn, w;
		cin >> pn >> cn >> w;
		tree[pn].push_back({cn, w});
		tree[cn].push_back({pn, w});
	}
	dfs(tree, 1);
	dfs(tree, ret);
	cout << dist << '\n';
}
