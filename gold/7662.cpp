#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int t, n, input;
	char cmd;
	cin >> t;
	while (t--)
	{
		cin >> n;
		map<int, int> dpq;
		while (n--)
		{
			cin >> cmd >> input;
			if (cmd == 'I')
			{
				if (dpq.count(input))
					dpq[input] += 1;
				else
					dpq[input] = 1;
			}
			else if (cmd == 'D')
			{
				if (dpq.empty())
					continue;
				if (input == -1)
				{
					dpq.begin()->second -= 1;
					if (dpq.begin()->second == 0)
						dpq.erase(dpq.begin()->first);
				}
				else if (input == 1)
				{
					dpq.rbegin()->second -= 1;
					if (dpq.rbegin()->second == 0)
						dpq.erase(dpq.rbegin()->first);
				}
			}
		}
		if (dpq.empty())
			cout << "EMPTY\n";
		else
			cout << dpq.rbegin()->first << ' ' << dpq.begin()->first << '\n';
	}
}
