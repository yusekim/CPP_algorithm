#include <iostream>
using namespace std;

int main()
{
	int	newnum;
	int	res;

	res = 0;
	while (cin >> newnum)
		res += newnum;
	cout << res << '\n';
}