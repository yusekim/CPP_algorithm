#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long getfib(long long N)
{
	long long k = N / 2, res;

	if (m.find(N) != m.end())
		return m[N];
	if (N % 2)
		res = getfib(k) * getfib(k) + getfib(k + 1) * getfib(k + 1);
	else
		res = getfib(k) * (getfib(k - 1) + getfib(k + 1));
	res = res % 1000000007;
	m[N] = res;
	return res;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long long N;
	cin >> N;
	m[0] = 0;
	m[1] = 1;
	m[2] = 1;
	cout << getfib(N) << '\n';
}
