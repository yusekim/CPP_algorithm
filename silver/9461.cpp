#include <iostream>
using namespace std;

long dp[100];

long waveseq(int n)
{
	if (dp[n])
		return dp[n];
	else
	{
		static int idx;
		while (dp[idx])
			idx++;
		while (idx <= n)
		{
			dp[idx] = dp[idx - 3] + dp[idx - 2];
			idx++;
		}
		return dp[n];
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 3; i++)
		dp[i] = 1;
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << waveseq(n - 1) << '\n';
	}
}
