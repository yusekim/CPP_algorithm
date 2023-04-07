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
		int	space = (input - index);
		while (space--)
			cout << ' ';
		int	num_stars = index * 2 - 1;
		while (num_stars--)
			cout << '*';
		cout << '\n';
		index++;
	}
}