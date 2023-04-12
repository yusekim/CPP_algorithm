#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string	str;
	vector<int> v(26);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		v[str[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << v[i] << ' ';
	cout << '\n';
}
