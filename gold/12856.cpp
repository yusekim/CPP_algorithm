#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, K;
	cin >> N >> K;
	vector<int> w(N + 1, 0), v(N + 1, 0);
	for (int idx = 1; idx <= N; idx++)
		cin >> w[idx] >> v[idx];
	vector<vector<int> > dp(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (w[i] <= j)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << *max_element(dp[N].begin(), dp[N].end()) << '\ n';
}


/* 1차원 dp
#include <iostream>
#include<vector>
using namespace std;
int main() {
	int n, k,w,v;
	cin>>n>>k;
	vector<int> dp(k+1,0);
	for(int i = 1; i <=n; i++){
		cin>>w>>v;
		for(int j = k; j>=w; j--){
			dp[j] = max(dp[j], dp[j-w]+v);
		}
	}
	cout<<dp[k];
}
*/
