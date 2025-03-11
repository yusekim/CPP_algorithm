#include <iostream>
#include <cmath>
using namespace std;

int dp[50001];

void filldp(int n)
{
	for (int i = 1; i * i <= n; i++)
	{
		if (dp[n] == 0)
			dp[n] = dp[i * i] + dp[n - i * i];
		else
			dp[n] = min(dp[n], dp[i * i] + dp[n - i * i]);
	}
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, res = 0;
	cin >> n;
	int val = sqrt(INT32_MAX);
	for (int i = 1; i <= n; i++)
	{
		if (i < val && i * i <= n)
			dp[i * i] = 1;
		if (dp[i] == 0)
			filldp(i);
	}
	cout << dp[n] << '\n';
}
