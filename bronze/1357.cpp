#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	rev(string X)	{
	int	exp	= X.length();
	int ret = 0;
	int	int_X = atoi(X.c_str());

	while (int_X) {
		ret += (int_X % 10) * pow(10, --exp);
		int_X /= 10;
	}
	return ret;
}

int	main() {
	fastio;
	string X, Y;
	cin >> X >> Y;

	string s = to_string(rev(X) + rev(Y));

	cout << rev(s) << '\n';
}
