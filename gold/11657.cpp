#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const int INF = 1e9;
int N, M, A, B, C;
vector<long long> dist(501, INF);
vector<tuple<int, int, int>> edges;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		edges.push_back({A, B, C});
	}
	dist[1] = 0;
	for (int i = 0; i < N - 1; i++)
		for (auto [u, v, w] : edges)
			if (dist[u] != INF && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
	bool isNegCycle = false;
	for (auto [u, v, w] : edges)
	{
		if (dist[u] != INF && dist[u] + w < dist[v])
		{
			isNegCycle = true;
			break;
		}
	}
	if (isNegCycle)
		cout << -1 << '\n';
	else
	{
		for (int i = 2; i <= N; i++)
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
	}
}
