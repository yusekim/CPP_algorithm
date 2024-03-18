#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;

	vector<pair<int, int> > V;
	while (N--) {
		int X, Y; cin >> X >> Y;
		V.push_back(make_pair(Y, X));
	}
	sort(V.begin(), V.end());
	for (auto iter = V.begin(); iter != V.end(); iter++) {
		cout << iter->second << ' ' << iter->first << '\n';
	}
	return 0;
}
