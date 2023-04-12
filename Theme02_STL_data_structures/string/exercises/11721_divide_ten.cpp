#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string s;
	int	i = 0;

	cin >> s;
	while (i < s.size())
	{
		for (int j = 0; j < 10 && s[i + j]; j++)
			cout << s[j + i];
		cout << '\n';
		i += 10;
	}
}
