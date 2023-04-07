#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() 
{
	fastio;
	int		N;
	string	s;
	int		i;
	int		t;
	int		ans;

	t = 0;
	cin >> N;
	cin.ignore();
	while (N--)
	{ 
		getline(cin, s);
		i = 0;
		ans = 0;
		while(i <= s.size())
		{
			if (i < s.size() && s[i] != ' ')
				t = 10 * t + s[i] - '0';
			else
			{
				ans += t;
				t = 0;
			}
			i++;
		}
		cout << ans << '\n';
	}
}