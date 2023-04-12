#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	n;
	int	m;
	int	cnt;

	cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> m;
	for (int i = 0; i < n; i++)
		if (v[i] == m) cnt++;
	cout << cnt << '\n';
}
