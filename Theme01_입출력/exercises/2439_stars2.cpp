#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	n;
	char	star = '*';
	int i = 1;

	cin >> n;
	while (i <= n)
	{
		int space = n - i;
		while (space--)
			cout << ' ';
		int j = 1;
		while (j++ <= i)
			cout << star;
		cout << '\n';
		i++;
	}
}