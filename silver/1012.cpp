#include <iostream>
#include <cstring>

#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int land[50][50] = {0};

void printland(int M, int N)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
			cout << land[y][x] << ' ';
		cout << '\n';
	}
}

void wormcover(int m, int n, int y, int x)
{
	if (land[y][x] != 1)
		return;
	else
	{
		land[y][x] = -1;
		if (x > 0)
			wormcover(m, n, y, x - 1);
		if (x < m - 1)
			wormcover(m, n, y, x + 1);
		if (y > 0)
			wormcover(m, n, y - 1, x);
		if (y < n - 1)
			wormcover(m, n, y + 1, x);
	}
}

void bfs(int m, int n)
{
	int res = 0;
	for (int y = 0; y < n; y++)
	{
		// cout << "Y IS: "<< y << '\n';
		for (int x = 0; x < m; x++)
		{
			// cout << "X IS: "<< x << '\n';
			if (land[y][x] == -1)
				continue;
			else if (land[y][x] == 1)
			{
				wormcover(m, n, y, x);
				res++;
				// printland(m, n);
			}
			land[y][x] = -1;
		}
	}
	cout << res << '\n';
}

int main()
{
	fastio;
	int T, N, M, K;
	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		while (K--)
		{
			int x, y;
			cin >> x >> y;
			land[y][x] = 1;
		}
		// cout << '\n';
		// printland(N , M);
		// cout << '\n';
		bfs(M, N);
		memset(land, 0, sizeof(land));
	}
}
