#include <iostream>
#include <queue>
using namespace std;

class coord
{
private:
public:
	int i, j, k;
	coord(int i, int j, int k);
	~coord();
};
coord::coord(int i_val, int j_val, int k_val) : i(i_val), j(j_val), k(k_val) {}
coord::~coord() {}

int m, n, h, unripe;
int storage[100][100][100];
bool visited[100][100][100];
queue<coord> que;

bool check(int i, int j, int k)
{
	if (visited[k][i][j] == 0 && storage[k][i][j] == 0)
	{
		visited[k][i][j] = 1;
		storage[k][i][j] = 1;
		unripe--;
		return true;
	}
	return false;
}

int bfs(size_t count)
{
	int res = 0;
	while (que.size())
	{
		if (count == 0)
		{
			res++;
			count = que.size();
		}
		coord top = que.front();
		que.pop();
		if (top.i > 0 && check(top.i - 1, top.j, top.k))
			que.push(coord(top.i - 1, top.j, top.k));
		if (top.i + 1 < n && check(top.i + 1, top.j, top.k))
			que.push(coord(top.i + 1, top.j, top.k));
		if (top.j > 0 && check(top.i, top.j - 1, top.k))
			que.push(coord(top.i, top.j - 1, top.k));
		if (top.j + 1 < m && check(top.i, top.j + 1, top.k))
			que.push(coord(top.i, top.j + 1, top.k));
		if (top.k > 0 && check(top.i, top.j, top.k - 1))
			que.push(coord(top.i, top.j, top.k - 1));
		if (top.k + 1 < h && check(top.i, top.j, top.k + 1))
			que.push(coord(top.i, top.j, top.k + 1));
		count--;
	}
	if (unripe)
		return -1;
	return res;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> storage[k][i][j];
				if (storage[k][i][j] == 0)
					unripe++;
				else if (storage[k][i][j] == 1)
				{
					que.push(coord(i, j, k));
					visited[k][i][j] = 1;
				}
			}
		}
	}
	if (unripe == 0)
		cout << "0\n";
	else
		cout << bfs(que.size()) << '\n';
}
