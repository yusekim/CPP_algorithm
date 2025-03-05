#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n;
	while (n--)
	{
		set<string> set;
		unordered_multimap<string, string> map;
		cin >> m;
		while (m--)
		{
			string name, type;
			cin >> name >> type;
			map.insert(make_pair(type, name));
			set.insert(type);
		}
		int count = 1;
		while (set.size())
		{
			count *= map.count(*set.begin()) + 1;
			set.erase(*set.begin());
		}
		cout << count - 1 << '\n';
	}
}
