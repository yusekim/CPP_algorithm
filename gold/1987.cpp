#include <iostream>
#include <vector>
using namespace std;
int R, C, res = 0;
vector<vector<char>> grid;
bool visited[26];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void bt(int r, int c, int cnt)
{
	if (cnt > res)
		res = cnt;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 0 || nr >= R || nc < 0 || nc >= C)
			continue;
		int next_alpha = grid[nr][nc] - 'A';
		if (visited[next_alpha])
			continue;
		visited[next_alpha] = true;
		bt(nr, nc, cnt + 1);
		visited[next_alpha] = false;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C;
	grid.resize(R, vector<char>(C));
	for (int i = 0; i < R; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < C; j++)
			grid[i][j] = str[j];
	}
	visited[grid[0][0] - 'A'] = true;
	bt(0, 0, 1);
	cout << res << '\n';
}
