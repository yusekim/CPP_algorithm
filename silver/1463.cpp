#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int find_value(int N) {
    vector<int> dp(N + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[N];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    cout << find_value(N) << '\n';
}
