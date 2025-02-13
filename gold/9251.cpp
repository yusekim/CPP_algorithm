#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s1, s2;
	cin >> s1 >> s2;
	size_t s1_len = s1.size(), s2_len = s2.size();
	vector<vector<int> > map(s1_len + 1, vector<int>(s2_len + 1, 0));
	for (int i = 1; i <= s1_len; i++)
	{
		for (int j = 1; j <= s2_len; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				map[i][j] = map[i - 1][j - 1] + 1;
			else
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
		}
	}
	cout << map[s1_len][s2_len] << '\n';
}
