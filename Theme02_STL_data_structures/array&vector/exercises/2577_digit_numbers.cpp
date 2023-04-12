#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	a, b, c;
	int	multi;
	vector<int> v(10);
	cin >> a >> b >> c;
	multi = a * b * c;
	while (multi)
	{
		v[multi % 10]++;
		multi /= 10;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}
