#include <iostream>
#include <map>
using namespace std;
map<int, int> cmap;
int n, m, val;

void bt(map<int, int>::iterator iter, int depths)
{
	if (depths == m)
	{
		for (auto it : cmap)
			for (int i = 0; i < it.second; i++)
				cout << it.first << ' ';
		cout << '\n';
		return;
	}
	for (auto it = iter; it != cmap.end(); it++)
	{
		it->second += 1;
		bt(it, depths + 1);
		it->second -= 1;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		cmap[val] = 0;
	}
	bt(cmap.begin(), 0);
}
