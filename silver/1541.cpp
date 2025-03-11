#include <iostream>
using namespace std;

int getval(string s, int &idx)
{
	int res = 0, num = 0;
	while (s[idx] && s[idx] != '-')
	{
		if (s[idx] == '+')
		{
			res += num;
			num = 0;
		}
		else
			num = num * 10 + s[idx] - '0';
		idx++;
	}
	idx--;
	return res + num;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string input;
	cin >> input;
	int idx = 0, res = 0, num = 0, len = input.size();
	while (input[idx] >= '0' && input[idx] <= '9')
		res = res * 10 + input[idx++] - '0';
	while (idx < len)
	{
		if (input[idx] == '-')
			res -= getval(input, ++idx);
		else if (input[idx] == '+')
		{
			res += num;
			num = 0;
		}
		else
			num = num * 10 + input[idx] - '0';
		idx++;
	}
	cout << res + num << '\n';
}
