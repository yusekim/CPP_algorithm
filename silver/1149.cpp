#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, prev = -1;
	cin >> N;
	vector<vector<int> > dp(3, vector<int>(1001));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> dp[j][i];
	for (int i = 1; i <= N; i++)
	{
		dp[0][i] += min(dp[1][i - 1], dp[2][i - 1]);
		dp[1][i] += min(dp[0][i - 1], dp[2][i - 1]);
		dp[2][i] += min(dp[0][i - 1], dp[1][i - 1]);
	}
	cout << min(min(dp[0][N], dp[1][N]), dp[2][N]) << '\n';
}
