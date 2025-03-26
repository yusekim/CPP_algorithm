#include <iostream>
#include <map>
using namespace std;

map<int, pair<int, int> > m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	while (n--)
	{
		int input;
		cin >> input;
		if (input == 0)
		{
			if (m.empty())
				cout << 0 << '\n';
			else
			{
				auto it = m.begin();
				cout << it->first * ((it->second.first > 0) ? -1 : 1) << '\n';
				if (it->second.first > 0)
					it->second.first--;
				else
					it->second.second--;
				if (it->second.first == 0 && it->second.second == 0)
					m.erase(it->first);
			}
		}
		else
		{
			int abs = input * ((input < 0) ? -1 : 1);
			pair<int, int> p(0, 0);
			auto target = m.find(abs);
			if (target == m.end())
			{
				if (input < 0)
					p.first++;
				else
					p.second++;
				m[abs] = p;
			}
			else
			{
				if (input < 0)
					target->second.first++;
				else
					target->second.second++;
			}
		}
	}
}
