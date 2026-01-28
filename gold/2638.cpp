#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, res = 0;
vector<pair<int, int>> cheese;
int map[100][100];
bool visited[100][100];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void bfs()
{
	queue<pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	visited[0][0] = true;
	q.push({0, 0});
	while (q.size())
	{
		auto [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == 0 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				cheese.push_back({i, j});
		}
	}
	while (cheese.size())
	{
		bfs();
		for (auto it = cheese.begin(); it != cheese.end();)
		{
			auto [x, y] = *it;
			int cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if (visited[nx][ny] == true)
					cnt++;
			}
			if (cnt >= 2)
			{
				it = cheese.erase(it);
				map[x][y] = 0;
			}
			else
				it++;
		}
		res++;
	}
	cout << res << '\n';
}
