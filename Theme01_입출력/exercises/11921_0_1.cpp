#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int		N;
	int		res = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		res += input;
	}
	cout << N << '\n' << res << '\n';
}