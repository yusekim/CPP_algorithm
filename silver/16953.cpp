#include <iostream>
#include <map>
#include <queue>
using namespace std;

int a, b;
map<int, int> m;

int bfs()
{
	queue<int> que;
	que.push(b);
	m[b] = 1;
	while (que.size())
	{
		int val = que.front();
		que.pop();
		if (val < a)
			continue;
		else if (val == a)
			return m[val];
		else
		{
			if (val % 2 == 0 && m.count(val / 2) == 0)
			{
				que.push(val / 2);
				m[val / 2] = m[val] + 1;
			}
			if (val % 10 == 1 && val / 10 > 0 && m.count(val / 10) == 0)
			{
				que.push(val / 10);
				m[val / 10] = m[val] + 1;
			}
		}
	}
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	cout << bfs() << '\n';
}
