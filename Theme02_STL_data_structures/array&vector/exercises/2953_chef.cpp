#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	res[2] = {0, 0};

	for (int i = 1; i <= 5; i++)
	{
		int a, b, c, d, temp;
		cin >> a >> b >> c >> d;
		temp = a + b + c + d;
		if (temp > res[1])
		{
			res[0] = i;
			res[1] = temp;
		}
	}
	cout << res[0] << ' ' << res[1] << '\n';
}
