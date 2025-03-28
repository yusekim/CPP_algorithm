#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

vector<int> arr(101, -1);

void bfs(map<int, int> &ladder, map<int, int> &snake)
{
	queue<int> q;
	q.push(1);
	arr[1] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int dice = 1; dice <= 6; dice++)
		{
			int next = now + dice;
			if (next > 100)
				continue;

			if (ladder.count(next))
				next = ladder[next];
			else if (snake.count(next))
				next = snake[next];

			if (arr[next] == -1)
			{
				arr[next] = arr[now] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m, x, y;
	cin >> n >> m;

	map<int, int> ladder, snake;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		ladder[x] = y;
	}
	for (int j = 0; j < m; j++)
	{
		cin >> x >> y;
		snake[x] = y;
	}

	bfs(ladder, snake);
	cout << arr[100] << '\n';
}
