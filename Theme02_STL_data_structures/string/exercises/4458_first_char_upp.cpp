#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int		N;

	cin >> N;
	cin.ignore();
	while (N--)
	{
		string	s;
		getline(cin, s);
		if (s[0] >= 'a' && s[0] <= 'z')
			s[0] = s[0] - ' ';
		cout << s << '\n';
	}
}
