#include <iostream>
using namespace std;

char arr[600][600];
bool visited[600][600];
int n, m, res = 0;

void dfs(int i, int j)
{
	cout << "coord: " << j << ' ' << i << '\n';
	visited[i][j] = true;
	if (arr[i][j] == 'P')
		res++;
	if (i - 1 >= 0 && visited[i - 1][j] == false && arr[i - 1][j] != 'X')
		dfs(i - 1, j);
	if (i + 1 < n && visited[i + 1][j] == false && arr[i + 1][j] != 'X')
		dfs(i + 1, j);
	if (j - 1 >= 0 && visited[i][j - 1] == false && arr[i][j - 1] != 'X')
		dfs(i, j - 1);
	if (j + 1 < m && visited[i][j + 1] == false && arr[i][j + 1] != 'X')
		dfs(i, j + 1);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	pair<int, int> start;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'I')
				start = make_pair(i, j);
		}
	}
	cout << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j];
		cout << '\n';
	}
	dfs(start.first, start.second);
	if (res > 0)
		cout << res << '\n';
	else
		cout << "TT\n";
}
