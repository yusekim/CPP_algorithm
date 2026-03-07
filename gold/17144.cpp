#include <iostream>
#include <cstring>
using namespace std;
int R, C, T, idx, nidx, ap = 0, res = 0;
int map[2][50][50];

void micro_dust()
{
	int cnt;
	idx = T % 2;
	nidx = (idx + 1) % 2;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	memset(map[nidx], 0, sizeof(map[nidx]));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[idx][i][j] >= 5)
			{
				cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (ni < 0 || ni >= R || nj < 0 || nj >= C || map[idx][ni][nj] == -1)
						continue;
					map[nidx][ni][nj] += map[idx][i][j] / 5;
					cnt++;
				}
				map[nidx][i][j] += (map[idx][i][j] - map[idx][i][j] / 5 * cnt);
			}
			else
				map[nidx][i][j] += map[idx][i][j];
		}
	}
	for (int i = ap - 1; i > 0; i--)
		map[nidx][i][0] = map[nidx][i - 1][0];
	for (int i = ap + 2; i < R - 1; i++)
		map[nidx][i][0] = map[nidx][i + 1][0];
	for (int i = 0; i < C - 1; i++)
	{
		map[nidx][0][i] = map[nidx][0][i + 1];
		map[nidx][R - 1][i] = map[nidx][R - 1][i + 1];
	}
	for (int i = 0; i < ap; i++)
		map[nidx][i][C - 1] = map[nidx][i + 1][C - 1];
	for (int i = R - 1; i > ap + 1; i--)
		map[nidx][i][C - 1] = map[nidx][i - 1][C - 1];
	for (int i = C - 1; i > 1; i--)
	{
		map[nidx][ap][i] = map[nidx][ap][i - 1];
		map[nidx][ap + 1][i] = map[nidx][ap + 1][i - 1];
	}
	map[nidx][ap][1] = 0;
	map[nidx][ap + 1][1] = 0;
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C >> T;

	idx = (T - 1) % 2;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[idx][i][j];
			if (ap == 0 && map[idx][i][j] == -1)
				ap = i;
		}
	}

	while (T--)
		micro_dust();

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			if (map[nidx][i][j] > 0)
				res += map[nidx][i][j];
	}
	cout << res << '\n';
}
