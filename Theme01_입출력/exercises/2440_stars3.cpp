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
		int j = n - i + 1;
		while (j--)
			cout << star;
		cout << '\n';
		i++;
	}
}