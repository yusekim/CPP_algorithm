#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char arr[100][100];
int n, m;

int bfs(vector<vector<unsigned int> > &visited)
{
	queue<pair<int, int> > que;
	que.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (que.size())
	{
		int i = que.front().first, j = que.front().second;
		que.pop();
		if (i > 0 && arr[i - 1][j] == '1')
		{
			if (visited[i - 1][j] == -1)
				que.push(make_pair(i - 1, j));
			visited[i - 1][j] = min(visited[i - 1][j], visited[i][j] + 1);
		}
		if (i + 1 < n && arr[i + 1][j] == '1')
		{
			if (visited[i + 1][j] == -1)
				que.push(make_pair(i + 1, j));
			visited[i + 1][j] = min(visited[i + 1][j], visited[i][j] + 1);
		}
		if (j > 0 && arr[i][j - 1] == '1')
		{
			if (visited[i][j - 1] == -1)
				que.push(make_pair(i, j - 1));
			visited[i][j - 1] = min(visited[i][j - 1], visited[i][j] + 1);
		}
		if (j + 1 < m && arr[i][j + 1] == '1')
		{
			if (visited[i][j + 1] == -1)
				que.push(make_pair(i, j + 1));
			visited[i][j + 1] = min(visited[i][j + 1], visited[i][j] + 1);
		}
	}
	return (visited[n - 1][m - 1]);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	vector<vector<unsigned int> > visited(n, vector<unsigned int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j];
	}
	cout << bfs(visited) << '\n';
}
