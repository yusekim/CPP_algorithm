#include <iostream>
#include <vector>

using namespace std;
vector<int> save(12, 0);

int getcomb(int val)
{
	int res = 0;
	if (save[val])
		return save[val];
	else
		res += getcomb(val - 1) + getcomb(val - 2) + getcomb(val - 3);
	save[val] = res;
	return res;
}

int main()
{
	save[1] = 1;
	save[2] = 2;
	save[3] = 4;
	save[4] = 7;

	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	while (N--)
	{
		int val;
		cin >> val;
		int res = getcomb(val);
		cout << res << '\n';
	}
}
