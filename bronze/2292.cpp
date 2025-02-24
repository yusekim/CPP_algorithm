#include <iostream>

using namespace std;

int main()
{
	int arr[18257] = {0};
	cin.tie(0)->sync_with_stdio(0);
	int N, val = 1, i = 1;
	cin >> N;
	if (N == 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	while (val < N)
	{
		arr[i - 1] = val;
		val += 6 * i++;
	}
	cout << i - (((N - arr[i - 1]) == 1) ? 1 : 0) << '\n';
}
