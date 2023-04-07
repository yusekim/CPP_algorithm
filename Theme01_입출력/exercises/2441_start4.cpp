#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	n;
	char	star = '*';
	int i = 0;

	cin >> n;
	while (n - i)
	{
		int j = n;
		int	space = i;
		while (space--)
			cout << ' ';
		while (j-- - i)
			cout << star;
		cout << '\n';
		i++;
	}
}