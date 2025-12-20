#include <iostream>
#include <vector>
using namespace std;
int N;
int map[17][17];
long long dp[17][17][3];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map[i][j];
	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 1)
				continue;
			if (dp[i][j][0] > 0)
			{
				if (j + 1 <= N && map[i][j + 1] == 0)
					dp[i][j + 1][0] += dp[i][j][0];
				if (i + 1 <= N && j + 1 <= N && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					dp[i + 1][j + 1][2] += dp[i][j][0];
			}
			if (dp[i][j][1] > 0)
			{
				if (i + 1 <= N && map[i + 1][j] == 0)
					dp[i + 1][j][1] += dp[i][j][1];
				if (i + 1 <= N && j + 1 <= N && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					dp[i + 1][j + 1][2] += dp[i][j][1];
			}
			if (dp[i][j][2] > 0)
			{
				if (j + 1 <= N && map[i][j + 1] == 0)
					dp[i][j + 1][0] += dp[i][j][2];
				if (i + 1 <= N && map[i + 1][j] == 0)
					dp[i + 1][j][1] += dp[i][j][2];
				if (i + 1 <= N && j + 1 <= N && map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					dp[i + 1][j + 1][2] += dp[i][j][2];
			}
		}
	}
	long long res = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	cout << res << '\n';
}
