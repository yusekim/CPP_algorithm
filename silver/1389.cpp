#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
pair<int, int> kb;

void bfs(vector<vector<int> > &vec, int start)
{
	queue<int> que;
	bool visited[100] = {false};
	int count = 0, hop = 1, next = 1;
	que.push(start);
	visited[start] = true;
	while (que.size())
	{
		int val = que.front();
		que.pop();
		for (int i = 0; i < vec[val].size(); i++)
		{
			if (visited[vec[val][i]] == false)
			{
				count += hop;
				visited[vec[val][i]] = true;
				que.push(vec[val][i]);
			}
		}
		next--;
		if (next == 0)
		{
			hop++;
			next = que.size();
		}
	}
	if (kb.first == 0)
		kb = make_pair(start + 1, count);
	else if (count < kb.second)
		kb = make_pair(start + 1, count);
	else if (count == kb.second && kb.first > start + 1)
		kb = make_pair(start + 1, count);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	vector<vector<int> > vec(n);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		vec[a - 1].push_back(b - 1);
		vec[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++)
		bfs(vec, i);
	cout << kb.first << '\n';
}

//플로이드-워셜 알고리즘
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, INF));
	for (int i = 0; i < n; i++)
		dist[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int answer = -1;
	int minSum = INF;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += dist[i][j];
		if (sum < minSum)
		{
			minSum = sum;
			answer = i;
		}
	}
	cout << answer + 1 << "\n";
	return 0;
}

