#include <iostream>
#include <queue>
using namespace std;

int map[100][100], cb_map[100][100];
int n;

int bfs(int m[100][100])
{
	queue<pair<int, int> > que;
	bool v[100][100] = {false};
	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!v[i][j])
			{
				int cur = m[i][j];
				que.push(make_pair(i, j));
				v[i][j] = true;
				while (!que.empty())
				{
					int x = que.front().first, y = que.front().second;
					que.pop();

					const int dx[4] = {-1, 1, 0, 0};
					const int dy[4] = {0, 0, -1, 1};

					for (int d = 0; d < 4; ++d)
					{
						int nx = x + dx[d], ny = y + dy[d];
						if (nx >= 0 && ny >= 0 && nx < n && ny < n)
						{
							if (!v[nx][ny] && m[nx][ny] == cur)
							{
								v[nx][ny] = true;
								que.push(make_pair(nx, ny));
							}
						}
					}
				}
				res++;
			}
		}
	}
	return res;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j];
			if (str[j] == 'R' || str[j] == 'G')
				cb_map[i][j] = 'G';
			else
				cb_map[i][j] = str[j];
		}
	}
	cout << bfs(map) << ' ' << bfs(cb_map) << '\n';
}
