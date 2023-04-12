#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int		flag = 0;
	int		temp = 0;

	for (int i = 0; i < 8; i++)
	{
		int	a;
		cin >> a;
		if (!temp)
		{
			temp = a;
			continue;
		}
		if ((flag == 1 && a < temp) || (flag == 2 && a > temp))
		{
			flag = 0;
			break ;
		}
		if ((!flag || flag == 1) && a > temp)
			flag = 1;
		if ((!flag || flag == 2) && a < temp)
			flag = 2;
		temp = a;
	}
	if (flag == 0)
		cout << "mixed" << '\n';
	if (flag == 1)
		cout << "ascending" << '\n';
	if (flag == 2)
		cout << "descending" << '\n';
}
