#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, res = 0;
vector<pair<int, int>> wall, virus;
int map[8][8];

void bfs()
{
	int copy[8][8];
	memcpy(copy, map, sizeof(map));
	queue<pair<int, int>> q;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);

	while (q.size())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || copy[nx][ny] != 0)
				continue;
			copy[nx][ny] = 2;
			q.push({nx, ny});
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copy[i][j] == 0)
				cnt++;
		}
	}
	if (cnt > res)
		res = cnt;
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
			if (map[i][j] == 0)
				wall.push_back({i, j});
			if (map[i][j] == 2)
				virus.push_back({i, j});
		}
	}

	int size = wall.size();
	for (int i = 0; i < size; i++)
	{
		map[wall[i].first][wall[i].second] = 1;
		for (int j = i + 1; j < size; j++)
		{
			map[wall[j].first][wall[j].second] = 1;
			for (int k = j + 1; k < size; k++)
			{
				map[wall[k].first][wall[k].second] = 1;
				bfs();
				map[wall[k].first][wall[k].second] = 0;
			}
			map[wall[j].first][wall[j].second] = 0;
		}
		map[wall[i].first][wall[i].second] = 0;
	}
	cout << res << '\n';
}
