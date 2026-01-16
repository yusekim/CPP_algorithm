#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
vector<vector<pair<int, int>>> villages(1001);
vector<vector<pair<int, int>>> r_villages(1001);
vector<int> dist(1001, INF), r_dist(1001, INF);
int N, M, X;

void dijkstra(int start, vector<vector<pair<int, int>>> &vill, vector<int> &dist)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	dist[start] = 0;
	while (pq.size())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();
		if (dist[cur_node] < cur_dist)
			continue;
		for (int i = 0; i < vill[cur_node].size(); i++)
		{
			int n_node = vill[cur_node][i].second;
			int n_dist = cur_dist + vill[cur_node][i].first;
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
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		villages[a].push_back({c, b});
		r_villages[b].push_back({c, a});
	}
	dijkstra(X, villages, dist);
	dijkstra(X, r_villages, r_dist);
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		int tmp = dist[i] + r_dist[i];
		if (res < tmp)
			res = tmp;
	}
	cout << res << '\n';
}
