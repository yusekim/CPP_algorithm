#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int M, N;
queue<pair<int, int> > startpoints;

void bfs(vector<vector<int> > &map)
{
	pair<int, int> point = startpoints.front();
	startpoints.pop();
	if (point.first > 0 && map[point.first - 1][point.second] == 0)
	{
		map[point.first - 1][point.second] = map[point.first][point.second] + 1;
		startpoints.push(make_pair(point.first - 1, point.second));
	}
	if (point.first < N - 1 && map[point.first + 1][point.second] == 0)
	{
		map[point.first + 1][point.second] = map[point.first][point.second] + 1;
		startpoints.push(make_pair(point.first + 1, point.second));
	}
	if (point.second > 0 && map[point.first][point.second - 1] == 0)
	{
		map[point.first][point.second - 1] = map[point.first][point.second] + 1;
		startpoints.push(make_pair(point.first, point.second - 1));
	}
	if (point.second < M - 1 && map[point.first][point.second + 1] == 0)
	{
		map[point.first][point.second + 1] = map[point.first][point.second] + 1;
		startpoints.push(make_pair(point.first, point.second + 1));
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N;
	vector<vector<int> > map;
	for(int i = 0; i < N; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < M; j++)
		{
			int value;
			cin >> value;
			if (value == 1)
				startpoints.push(make_pair(i, j));
			tmp.push_back(value);
		}
		map.push_back(tmp);
		tmp.clear();
	}
	while (!startpoints.empty())
		bfs(map);
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
			else if (map[i][j] > res)
				res = map[i][j];
		}
	}
	cout << res - 1 << '\n';
}
