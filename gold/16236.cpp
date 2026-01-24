#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int N, res = 0;
int map[20][20];
bool visited[20][20];
int b_shark[4];

int bfs()
{
	queue<tuple<int, int, int>> q;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> fishes;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};

	memset(visited, 0, sizeof(visited));
	visited[b_shark[0]][b_shark[1]] = true;
	q.push({0, b_shark[0], b_shark[1]});
	while (q.size())
	{
		auto [cur_d, cur_x, cur_y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			int nd = cur_d + 1;
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (map[nx][ny] <= b_shark[2] && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push({nd, nx, ny});
				if (map[nx][ny] > 0 && map[nx][ny] < b_shark[2])
				{
					fishes.push({nd, {nx, ny}});
				}
			}
		}
	}
	if (fishes.size() > 0)
	{
		int dist = fishes.top().first;
		int fx = fishes.top().second.first;
		int fy = fishes.top().second.second;
		res += dist;
		map[fx][fy] = 0;
		b_shark[0] = fx;
		b_shark[1] = fy;
		b_shark[3] += 1;
		if (b_shark[3] == b_shark[2])
		{
			b_shark[2] += 1;
			b_shark[3] = 0;
		}
		return dist;
	}
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				b_shark[0] = i;
				b_shark[1] = j;
				b_shark[2] = 2;
				b_shark[3] = 0;
				map[i][j] = 0;
			}
		}
	}
	while (bfs()) ;
	cout << res << '\n';
}
