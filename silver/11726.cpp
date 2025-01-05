#include <iostream>
#include <vector>
using namespace std;

vector <int> vec(1001, 0);

int dp(int n)
{
	if (vec[n] == 0)
		vec[n] = (dp(n - 1) + dp(n - 2)) % 10007;
	return vec[n];
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vec[1] = 1;
	vec[2] = 2;
	cout << dp(N) << '\n';
}
