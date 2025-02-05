#include <iostream>

using namespace std;

long calculate(long a, long b, long c)
{
	if (b == 0)
		return 1;
	else if (b % 2)
		return (a % c * calculate(a, b - 1, c)) % c;
	else
	{
		long val = calculate(a, b / 2, c) % c;
		return (val * val) % c;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	long a, b, c;
	cin >> a >> b >> c;
	cout << calculate(a, b, c) << '\n';
}
