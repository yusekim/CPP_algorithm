#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 200000000;
int N, E, v1, v2;
// 1 -> v1 -> v2 -> N
// 1 -> v2 -> v1 -> N

int dijkstra(vector<vector<pair<int, int>>> &routes, int start, int dest)
{
	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start] = 0;
	while (pq.size())
	{
		unsigned int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (dist[cur_node] < cur_dist)
			continue;
		for (int i = 0; i < routes[cur_node].size(); i++)
		{
			int next_node = routes[cur_node][i].first;
			int next_dist = cur_dist + routes[cur_node][i].second;
			if (next_dist < dist[next_node])
			{
				dist[next_node] = next_dist;
				pq.push({next_dist, next_node});
			}
		}
	}
	return dist[dest];
}

void s_dijkstra(vector<vector<pair<int, int>>> &routes, int* ckpoints, long long &res)
{
	res = 0;
	for (int i = 0; i < 3; i++)
	{
		int tmp = dijkstra(routes, ckpoints[i], ckpoints[i + 1]);
		if (tmp == INF)
		{
			res = -1;
			return;
		}
		res += (long long)tmp;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> E;
	vector<vector<pair<int, int>>> routes(N + 1);
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		routes[a].push_back({b, c});
		routes[b].push_back({a, c});
	}
	cin >> v1 >> v2;
	long long res1, res2;
	int ckpoints[4] = {1, v1, v2, N};
	s_dijkstra(routes, ckpoints, res1);
	ckpoints[1] = v2;
	ckpoints[2] = v1;
	s_dijkstra(routes, ckpoints, res2);
	cout << min(res1, res2) << '\n';
}
