#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	c;
	
	cin >> c;
	while (c--)
	{
		int	a;
		int	b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
}