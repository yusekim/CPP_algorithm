#include <iostream>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, res = 0;
	cin >> N;
	while (N / 5)
	{
		res += N / 5;
		N /= 5;
	}
	cout << res << '\n';
}
