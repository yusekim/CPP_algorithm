#include <iostream>
using namespace std;
int dp[1001];
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		if (i % 2)
			dp[i] = dp[i - 1] * 2 - 1;
		else
			dp[i] = dp[i - 1] * 2 + 1;
		dp[i] %= 10007;
	}
	cout << dp[n] << '\n';
}
