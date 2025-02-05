#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> vec(N), dp(N, 1);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	for (int i = 1; i <= vec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[j] < vec[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';
}
