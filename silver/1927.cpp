#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<int> pque;

	int N, M;
	cin >> N;
	while (N--)
	{
		cin >> M;
		if (M == 0)
		{
			if (pque.empty())
				cout << 0 << '\n';
			else
			{
				cout << pque.top() * -1 << '\n';
				pque.pop();
			}
		}
		else
			pque.push(M * -1);
	}
}
