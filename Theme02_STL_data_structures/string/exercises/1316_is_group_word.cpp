#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string s;
	int	N;

	cin >> N;
	for (int i = N; i; i--)
	{
		vector<int> v(26, -1);
		cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (v[s[i] - 'a'] != -1 && v[s[i] - 'a'] != i - 1)
			{
				N--;
				break ;
			}
			v[s[i] - 'a'] = i;
		}
	}
	cout << N << '\n';
}
