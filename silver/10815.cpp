#include <iostream>
#include <set>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;
	set<int> S1;
	while (N--) {
		int val; cin >> val;
		S1.insert(val);
	}
	int M; cin >> M;
	while (M--) {
		int val; cin >> val;
		if (S1.count(val))
			cout << 1;
		else
			cout << 0;
		cout << ' ';
	}
	cout << '\n';
	return 0;
}
