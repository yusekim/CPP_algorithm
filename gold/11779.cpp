#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> routes(1001);
vector<pair<int, int>> dist(1001, pair<int, int>{INF, 0});
int n, m, start, dest;

void dijkstra(int start, int dest)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start].first = 0;
	while (pq.size())
	{
		int cur_d = pq.top().first;
		int cur_n = pq.top().second;
		pq.pop();
		if (dist[cur_n].first < cur_d)
			continue;
		for (int i = 0; i < routes[cur_n].size(); i++)
		{
			int n_node = routes[cur_n][i].second;
			int n_dist = cur_d + routes[cur_n][i].first;
			if (n_dist < dist[n_node].first)
			{
				dist[n_node].first = n_dist;
				dist[n_node].second = cur_n;
				pq.push({n_dist, n_node});
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		routes[u].push_back({w, v});
	}
	cin >> start >> dest;
	dijkstra(start, dest);
	cout << dist[dest].first << '\n';
	vector<int> res(1, dest);
	while (dest != start)
	{
		res.push_back(dist[dest].second);
		dest = dist[dest].second;
	}
	cout << res.size() << '\n';
	for (auto it = res.rbegin(); it != res.rend(); it++)
		cout << *it << ' ';
	cout << '\n';
}
