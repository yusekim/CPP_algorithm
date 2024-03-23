#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N, M; cin >> N >> M;
	set<string> S;

	while (N--) {
		string temp; cin >> temp;
		S.insert(temp);
	}
	vector<string> vec;
	int res = 0;
	while (M--) {
		string temp; cin >> temp;
		if (S.find(temp) != S.end()) {
			vec.push_back(temp);
			res++;
		}
	}
	cout << res << '\n';
	sort(vec.begin(), vec.end());
	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << '\n';
	}
}
