#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n, res = 0;

void bi_lis()
{
	vector<int> l(n, 1), r(n, 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				l[i] = max(l[i], l[j] + 1);
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j > i; j--)
			if (arr[j] < arr[i])
				r[i] = max(r[i], r[j] + 1);
	for (int i = 0; i < n; i++)
		if (res < l[i] + r[i] - 1)
			res = l[i] + r[i] - 1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bi_lis();
	cout << res << '\n';
}

