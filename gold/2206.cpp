#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;
int N, M, res = INF;
vector<vector<int>> map;
vector<pair<int, int>> walls;

void bfs()
{
	queue<pair<pair<int, int>, int>> q;
	vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, 0)));
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	q.push({{0, 0}, 0});
	visited[0][0][0] = 1;
	while (q.size())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall_used = q.front().second;
		q.pop();
		if (x == N - 1 && y == M - 1)
		{
			cout << visited[x][y][wall_used] << '\n';
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny] == 0 && visited[nx][ny][wall_used] == 0)
			{
				visited[nx][ny][wall_used] = visited[x][y][wall_used] + 1;
				q.push({{nx, ny}, wall_used});
			}
			if (map[nx][ny] == 1 && wall_used == 0 && visited[nx][ny][1] == 0)
			{
				visited[nx][ny][1] = visited[x][y][wall_used] + 1;
				q.push({{nx, ny}, 1});
			}
		}
	}
	cout << -1 << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	map.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
			map[i][j] = line[j] - '0';
	}
	bfs();
}
