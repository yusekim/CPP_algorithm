#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int TC, N, M, W, s, e, t;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M >> W;
		vector<tuple<int, int, int>> edges;
		vector<int> dist(N + 1, 0);
		bool isNegCycle = false;
		for (int i = 0; i < M; i++)
		{
			cin >> s >> e >> t;
			edges.push_back({s, e, t});
			edges.push_back({e, s, t});
		}
		for (int i = 0; i < W; i++)
		{
			cin >> s >> e >> t;
			edges.push_back({s, e, -t});
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (auto [u, v, w] : edges)
			{
				if (dist[u] + w < dist[v])
					dist[v] = dist[u] + w;
			}
		}
		for (auto [u, v, w] : edges)
		{
			if (dist[u] + w < dist[v])
			{
				isNegCycle = true;
				break;
			}
		}
		cout << (isNegCycle ? "YES" : "NO") << '\n';
	}
}
