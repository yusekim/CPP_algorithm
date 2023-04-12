#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	vector<int> v(2);

	int N;
	cin >> N;
	while (N--)
	{
		int a;
		cin >> a;
		if (!v[0] || v[0] > a)
			v[0] = a;
		if (v[1] < a)
			v[1] = a;
	}
	cout << v[0] << ' ' << v[1] << '\n';
}
