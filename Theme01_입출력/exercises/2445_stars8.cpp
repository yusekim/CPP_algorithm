#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	int	N;
	int	i = 1;
	int	star;
	int	space;

	cin >> N;
	while (i <= N)
	{
		star = i;
		while (star--)
			cout << '*';
		space = 2 * (N - i);
		while (space--)
			cout << ' ';
		star = i;
		while (star--)
			cout << '*';
		cout <<'\n';
		i++;
	}
	i = 1;
	while (i < N)
	{
		star = N - i;
		while (star--)
			cout <<'*';
		space = 2 * i;
		while (space--)
			cout << ' ';
		star = N - i;
		while (star--)
			cout << '*';
		cout << '\n';
		i++;
	}
}