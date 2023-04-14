#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main()
{
	fastio;
	int			N, val;
	stack<int>	S;

	cin >> N;
	while (N--)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			cin >> val;
			S.push(val);
		}
		else if (input == "top" || input == "pop")
		{
			if (!S.empty())
				cout << S.top() << '\n';
			else
				cout << -1 << '\n';
			if (input == "pop" && !S.empty())
				S.pop();
		}
		else if (input == "size")
			cout << S.size() << '\n';
		else if (input == "empty")
			cout << S.empty() << '\n';
	}
}
