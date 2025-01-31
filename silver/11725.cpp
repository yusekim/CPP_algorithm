#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited(100001, -1);
vector<vector<int> > tree(100001);
queue<int> q;

void bfs()
{
	visited[1] = 1;
	q.push(1);

	while (q.size())
	{
		int cur = q.front();
		q.pop();
		for (int x : tree[cur])
		{
			if (visited[x] == -1)
			{
				visited[x] = cur;
				q.push(x);
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	bfs();
	for (int i = 2; i <= N; i++)
		cout << visited[i] << '\n';
}
