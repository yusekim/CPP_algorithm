#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string	s;
	while (getline(cin, s))
	{
		int	low = 0, upp = 0, dig = 0, space = 0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				low++;
			if (s[i] >= 'A' && s[i] <= 'Z')
				upp++;
			if (s[i] >= '0' && s[i] <= '9')
				dig++;
			if (s[i] == ' ')
				space++;
		}
		cout << low << ' ' << upp << ' ' << dig << ' ' << space << '\n';
	}
}
