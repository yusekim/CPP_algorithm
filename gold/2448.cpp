#include <iostream>
#include <cstring>
using namespace std;
char map[3072][6144];

void rec(int n, int r, int c)
{
	if (n == 3)
	{
		map[r][c] = '*';
		map[r + 1][c - 1] = '*';
		map[r + 1][c + 1] = '*';
		for (int i = 0; i < 5; i++)
			map[r + 2][c - 2 + i] = '*';
	}
	else
	{
		int next_n = n / 2;
		rec(next_n, r, c);
		rec(next_n, r + next_n, c - next_n);
		rec(next_n, r + next_n, c + next_n);
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	memset(map, ' ', sizeof(map));
	rec(N, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout.write(map[i], 2 * N - 1);
		cout << '\n';
	}
}
