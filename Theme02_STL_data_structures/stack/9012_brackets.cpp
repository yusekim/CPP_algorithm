#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main()
{
	fastio;
	int	N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		stack<char> S;
		bool flag = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				S.push(s[i]);
			else
			{
				if (S.empty())
				{
					flag = 1;
					break ;
				}
				else
					S.pop();
			}
		}
		if (flag || !S.empty())
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}

}
