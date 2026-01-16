#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
int n, m;
vector<vector<int>> cost(101, vector<int>(101, INF));

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}
	for (int i = 1; i <= n; i++)
		cost[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (cost[i][k] + cost[k][j] < cost[i][j])
					cost[i][j] = cost[i][k] + cost[k][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cost[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << cost[i][j] << ' ';
		}
		cout << '\n';
	}
}
