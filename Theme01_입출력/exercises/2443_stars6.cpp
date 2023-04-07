#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	char	star = '*';
	int		input;
	int		index = 1;

	cin >> input;
	while (index <= input)
	{
		int	space = (index - 1);
		while (space-- > 0)
			cout << ' ';
		int	num_stars = 2 * (input - index) + 1;
		while (num_stars--)
			cout << '*';
		cout << '\n';
		index++;
	}
}