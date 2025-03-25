#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;

	int ans = 0, cnt = 0;

	for (int i = 1; i < m - 1; i++)
	{
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I')
		{
			cnt++;
			if (cnt == n)
			{
				ans++;
				cnt--;
			}
			i++;
		}
		else
			cnt = 0;
	}
	cout << ans << "\n";
}
