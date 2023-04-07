#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	long long		N;
	long long		i = 0;
	long long		res = 0;

	cin >> N;
	char	str[N + 1];
	cin >> str;
	while (i < N)
	{
		int	temp = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			temp = temp * 10 + str[i] - '0';
			i++;
		}
		res += temp;
		i++;
	}
	cout << res << '\n';
}