#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;

	vector<int> dp;
	for (int i = 0; i < N; i++)
	{
		vector<int> row(i + 1);
		for (int j = 0; j <= i; j++)
			cin >> row[j];
		if(i == 0)
			dp = row;
		else
		{
			vector<int> new_dp(i + 1, 0);
			new_dp[0] = dp[0] + row[0];
			new_dp[i] = dp[i - 1] + row[i];
			for (int j = 1; j < i; j++){
				new_dp[j] = row[j] + max(dp[j - 1], dp[j]);
			}
			dp = new_dp;
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
	return 0;
}
