#include <iostream>
#include <vector>
#include <cstdlib>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string str1, str2;
	int	cnt = 0;
	vector<int> a(26), b(26);
	cin >> str1 >> str2;
	for (int i = 0; i < str1.size(); i++)
		a[str1[i] - 'a']++;
	for (int i = 0; i < str2.size(); i++)
		b[str2[i] - 'a']++;
	for (int i = 0; i < 26; i++)
	{
		if (a[i] != b[i])
			cnt += abs(a[i] - b[i]);
	}
	cout << cnt << '\n';
}
