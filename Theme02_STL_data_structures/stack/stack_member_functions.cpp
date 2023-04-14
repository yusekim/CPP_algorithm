#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main()
{
	fastio;
	stack<int> S;

	for (int i = 10; i <= 50; i+= 10)
		S.push(i);	// S = [1, 2, 3, 4, 5(top)]
	while (!S.empty())
	{
		cout << S.size() << ' ' << S.top() << '\n';
		S.pop();
	}
}
