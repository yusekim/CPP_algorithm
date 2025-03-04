#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b;
	cin>>n;

	int arr[300];
	int dp[300];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	dp[1] = arr[0] + arr[1];
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for(int i = 3; i < n; i++)
	{
		a = dp[i - 2] + arr[i];
		b = dp[i - 3] + arr[i - 1] + arr[i];
		dp[i] = max(a, b);
	}
	cout << dp[n - 1];
}
