#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K, res = 0;
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	vector<int> values(N);
	for (int i = 0; i < N; i++)
		cin >> values[i];
	for (int i = N - 1; i >= 0; i--)
	{
		while (K / values[i])
		{
			res += K / values[i];
			K %= values[i];
		}
		if (K == 0)
			break;
	}
	cout << res << '\n';
}
