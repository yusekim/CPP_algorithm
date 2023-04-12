#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	vector<int> v(2);

	for (int i = 1; i <= 9; i++)
	{
		int	a;
		cin >> a;
		if (a > v[1])
		{
			v[0] = i;
			v[1] = a;
		}
	}
	cout << v[1] << '\n' << v[0] << '\n';
}
