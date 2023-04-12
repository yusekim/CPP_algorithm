#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		cout << s[0] << s[s.size() - 1] << '\n';
	}
}
