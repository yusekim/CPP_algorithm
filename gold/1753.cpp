#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E, K;
vector<vector<pair<int, int>>> verticies(20001);
unsigned int dist[20001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start] = 0;
	while (pq.size())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (dist[cur_node] < cur_dist)
			continue;
		for (int i = 0; i < verticies[cur_node].size(); i++)
		{
			int n_node = verticies[cur_node][i].second;
			int n_dist = cur_dist + verticies[cur_node][i].first;
			if (n_dist < dist[n_node])
			{
				dist[n_node] = n_dist;
				pq.push({n_dist, n_node});
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> V >> E >> K;
	fill(dist, dist + V + 1, -1);
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		verticies[u].push_back({w, v});
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == -1)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}
