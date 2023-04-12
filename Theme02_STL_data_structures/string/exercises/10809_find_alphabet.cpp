#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	vector<int> v(26, -1);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (v[s[i] - 'a'] == -1)
			v[s[i] - 'a'] = i;
	}
	for (int it = 0; it < v.size(); it++)
		cout << v[it] << ' ';
	cout << '\n';
}
