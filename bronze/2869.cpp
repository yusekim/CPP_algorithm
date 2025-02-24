#include <iostream>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int a, b, v, res = 1;
	cin >> a >> b >> v;
	if (v > a)
		res += (v - a) / (a - b) + ((v - a) % (a - b) > 0);
	cout << res << '\n';
}
