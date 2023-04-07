#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	int	N;
	int	i = 0;
	int	space;
	int	stars;

	cin >> N;
	while (i < N)
	{
		space = i;
		while (space--)
			cout << ' ';
		stars = (N - i) * 2 - 1;
		while (stars--)
			cout << '*';
		cout << '\n';
		i++;
	}
	i = 2;
	while (i <= N)
	{
		space = N - i;
		while (space--)
			cout << ' ';
		stars = i * 2 - 1;
		while (stars--)
			cout << '*';
		cout << '\n';
		i++;
	}
}