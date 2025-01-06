#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M;


void bfs(vector<vector<int> > &map, queue<pair<int, int> > &que)
{
	while(que.size())
	{
		pair<int, int> point = que.front();
		que.pop();
		if (point.first > 0 && map[point.first - 1][point.second] < 0) // TODO: 조건 수정(seg fault)
		{
			que.push(make_pair(point.first - 1, point.second));
			map[point.first - 1][point.second] = map[point.first][point.second] + 1;
		}
		if (point.first < N - 1 && map[point.first + 1][point.second] < 0)
		{
			que.push(make_pair(point.first + 1, point.second));
			map[point.first + 1][point.second] = map[point.first][point.second] + 1;
		}
		if (point.second > 0 && map[point.first][point.second - 1] < 0)
		{
			que.push(make_pair(point.first, point.second - 1));
			map[point.first][point.second - 1] = map[point.first][point.second] + 1;
		}
		if (point.second < M - 1 && map[point.first][point.second + 1] < 0)
		{
			que.push(make_pair(point.first, point.second + 1));
			map[point.first][point.second + 1] = map[point.first][point.second] + 1;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;

	vector<vector<int> > map(N, vector<int>(M, 0));
	queue<pair<int, int> > que;
	pair<int, int> target_point;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			if (tmp == 2)
			{
				target_point = make_pair(i, j);
				tmp = 0;
			}
			map[i][j] = tmp * -1;
		}
	}
	if (target_point.first > 0 && map[target_point.first - 1][target_point.second] < 0)
	{
		que.push(make_pair(target_point.first - 1, target_point.second));
		map[target_point.first - 1][target_point.second] *= -1;
	}
	if (target_point.first < N - 1 && map[target_point.first + 1][target_point.second] < 0)
	{
		que.push(make_pair(target_point.first + 1, target_point.second));
		map[target_point.first + 1][target_point.second] *= -1;
	}
	if (target_point.second > 0 && map[target_point.first][target_point.second - 1] < 0)
	{
		que.push(make_pair(target_point.first, target_point.second - 1));
		map[target_point.first][target_point.second - 1] *= -1;
	}
	if (target_point.first < M - 1 && map[target_point.first][target_point.second + 1] < 0)
	{
		que.push(make_pair(target_point.first, target_point.second + 1));
		map[target_point.first][target_point.second + 1] *= -1;
	}
	bfs(map, que);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j] << ' ';
		cout << '\n';
	}
}
