#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string str1, str2;
	int	N;
	cin >> N;
	while (N--)
	{
		vector<int> a(26), b(26);
		bool flag = 1;
		cin >> str1 >> str2;
		for (int i = 0; i < str1.size(); i++)
			a[str1[i] - 'a']++;
		for (int i = 0; i < str2.size(); i++)
			b[str2[i] - 'a']++;
		for (int i = 0; i < 26; i++)
		{
			if (a[i] != b[i])
				flag = 0;
		}
		if (flag == 0)
			cout << str1 << " & " << str2 << " are NOT anagrams." << '\n';
		else
			cout << str1 << " & " << str2 << " are anagrams." << '\n';
	}
	return 0;
}
