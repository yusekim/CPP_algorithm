#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int> > apt;


void build_apt(int k)
{
	if (apt.size() < k)
		build_apt(k - 1);
	vector<int> vec(14, 1);
	// cout << "\nlevel " << k << ':';
	for (int i = 1; i < 14; i++)
	{
		vec[i] = apt[k - 1][i] + vec[i - 1];
		// cout << vec[i] << ' ';
	}
	// cout << '\n';
	apt.push_back(vec);
}

void dp(int k, int n)
{
	if (apt.size() - 1 < k)
		build_apt(k);
	cout << apt[k - 1][n] + apt[k][n - 1] << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T, k, n;
	cin >> T;
	vector<int> vec(14);
	iota(vec.begin(), vec.end(), 1);
	apt.push_back(vec);
	while (T--)
	{
		cin >> k >> n;
		dp(k, n - 1);
	}
}
