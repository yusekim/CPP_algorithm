#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main()
{
	fastio;
	for (string s; getline(cin, s) && s != ".";)
	{
		stack<char> S;
		bool flag = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				S.push(s[i]);
			else if (s[i] == ')')
			{
				if (S.empty() || S.top() != '(')
					flag = 1;
				else
					S.pop();
			}
			else if(s[i] == ']')
			{
				if (S.empty() || S.top() != '[')
					flag = 1;
				else
					S.pop();
			}
		}
		if (S.size())
			flag = 1;
		cout << (flag ? "no" : "yes") << '\n';
	}
}
