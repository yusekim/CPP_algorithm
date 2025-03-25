#include <iostream>
using namespace std;

int get_gcd(int m, int n)
{
	int a, b, temp;
	if (m > n)
	{
		a = m;
		b = n;
	}
	else
	{
		a = n;
		b = m;
	}
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, m, n, x, y, res, lcm, target;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> x >> y;
		lcm = m * n / get_gcd(m, n);
		res = 0;
		if (m < n)
		{
			target = m;
			res += x;
			y -= x;
			x = 0;
		}
		else
		{
			target = n;
			res += y;
			x -= y;
			y = 0;
		}
		while (x != 0 || y != 0)
		{
			if (res >= lcm)
			{
				res = -1;
				break;
			}
			x -= target;
			y -= target;
			res += target;
			while (x < 0)
				x += m;
			while (y < 0)
				y += n;
		}
		cout << res << '\n';
	}
}
