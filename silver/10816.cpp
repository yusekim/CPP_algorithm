#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;
	map<int, int> m;

	while (N--) {
		int temp; cin >> temp;
		if (m.find(temp) != m.end())
			m[temp]++;
		else
			m[temp] = 1;
	}
	int M; cin >> M;
	while (M--) {
		int temp; cin >> temp;
		cout << m[temp] << ' ';
	}
	cout << '\n';
}
