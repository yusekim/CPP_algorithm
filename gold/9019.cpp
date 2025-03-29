#include <iostream>
#include <queue>
using namespace std;

bool visited[10001];

string bfs(int start, int goal)
{
	queue<pair<int, string>> que;
	visited[start] = true;
	que.push({start, ""});

	while (!que.empty())
	{
		int val = que.front().first;
		string cmd = que.front().second;
		que.pop();
		if (val == goal)
			return cmd;
		int next;
		next = (2 * val) % 10000;
		if (!visited[next]) {
			visited[next] = true;
			que.push({next, cmd + 'D'});
		}
		next = (val == 0) ? 9999 : val - 1;
		if (!visited[next]) {
			visited[next] = true;
			que.push({next, cmd + 'S'});
		}
		next = (val % 1000) * 10 + (val / 1000);
		if (!visited[next]) {
			visited[next] = true;
			que.push({next, cmd + 'L'});
		}
		next = (val % 10) * 1000 + (val / 10);
		if (!visited[next]) {
			visited[next] = true;
			que.push({next, cmd + 'R'});
		}
	}
	return "";
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, start, goal;
	cin >> t;
	while (t--)
	{
		cin >> start >> goal;
		cout << bfs(start, goal) << '\n';
		fill(visited, visited + 10001, false);
	}
}
